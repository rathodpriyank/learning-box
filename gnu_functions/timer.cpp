#include <queue>
#include <functional>
#include <chrono>
#include <mutex>
#include <thread>
#include <condition_variable>
#include <atomic>
#include <memory>
#include <vector>
#include <iostream>

class Timer {
private:
    struct TimerEvent {
        std::chrono::steady_clock::time_point execution_time;
        std::function<void()> callback;
        int id;

        TimerEvent(std::chrono::steady_clock::time_point time, 
                  std::function<void()> cb, 
                  int event_id)
            : execution_time(time), callback(cb), id(event_id) {}

        // Custom comparator for priority queue (min heap)
        bool operator>(const TimerEvent& other) const {
            return execution_time > other.execution_time;
        }
    };

    // Priority queue to store timer events (min heap)
    std::priority_queue<TimerEvent, 
                       std::vector<TimerEvent>, 
                       std::greater<TimerEvent>> timer_queue_;
    
    std::mutex mutex_;
    std::condition_variable cv_;
    std::atomic<bool> running_{false};
    std::thread worker_thread_;
    int next_timer_id_{0};

    void worker_function() {
        while (running_) {
            std::unique_lock<std::mutex> lock(mutex_);
            
            if (timer_queue_.empty()) {
                cv_.wait(lock, [this] { 
                    return !running_ || !timer_queue_.empty(); 
                });
                continue;
            }

            auto now = std::chrono::steady_clock::now();
            const auto& top_event = timer_queue_.top();

            if (top_event.execution_time <= now) {
                // Execute the callback
                TimerEvent event = timer_queue_.top();
                timer_queue_.pop();
                lock.unlock();
                
                try {
                    event.callback();
                } catch (const std::exception& e) {
                    // Handle callback exceptions
                    // You might want to add proper error handling here
                }
            } else {
                // Wait until the next timer event or until notified
                cv_.wait_until(lock, top_event.execution_time, [this] {
                    return !running_;
                });
            }
        }
    }

public:
    Timer() = default;
    ~Timer() {
        stop();
    }

    // Prevent copying
    Timer(const Timer&) = delete;
    Timer& operator=(const Timer&) = delete;

    // Start the timer service
    void start() {
        if (!running_) {
            running_ = true;
            worker_thread_ = std::thread(&Timer::worker_function, this);
        }
    }

    // Stop the timer service
    void stop() {
        if (running_) {
            {
                std::lock_guard<std::mutex> lock(mutex_);
                running_ = false;
            }
            cv_.notify_all();
            if (worker_thread_.joinable()) {
                worker_thread_.join();
            }
        }
    }

    // Set a timer that will execute the callback after the specified duration
    int set_timer(std::chrono::milliseconds duration, std::function<void()> callback) {
        if (!running_) {
            throw std::runtime_error("Timer service is not running");
        }

        auto execution_time = std::chrono::steady_clock::now() + duration;
        int timer_id = next_timer_id_++;

        {
            std::lock_guard<std::mutex> lock(mutex_);
            timer_queue_.emplace(execution_time, callback, timer_id);
        }
        
        cv_.notify_one();
        return timer_id;
    }

    // Cancel a specific timer by ID
    bool cancel_timer(int timer_id) {
        std::lock_guard<std::mutex> lock(mutex_);
        
        // Create a temporary queue to hold non-cancelled timers
        std::priority_queue<TimerEvent, 
                          std::vector<TimerEvent>, 
                          std::greater<TimerEvent>> temp_queue;
        
        bool found = false;
        while (!timer_queue_.empty()) {
            const auto& event = timer_queue_.top();
            if (event.id != timer_id) {
                temp_queue.push(std::move(timer_queue_.top()));
            } else {
                found = true;
            }
            timer_queue_.pop();
        }
        
        timer_queue_ = std::move(temp_queue);
        return found;
    }

    // Check if there are any pending timers
    bool has_pending_timers() const {
        std::lock_guard<std::mutex> lock(const_cast<std::mutex&>(mutex_));
        return !timer_queue_.empty();
    }
};

// Example usage:
int main() {
    Timer timer;
    timer.start();

    // Set a timer that executes after 1 second
    int timer_id = timer.set_timer(std::chrono::seconds(1), []() {
        std::cout << "Timer executed after 1 second!" << std::endl;
    });

    // Set another timer that executes after 2 seconds
    timer.set_timer(std::chrono::seconds(2), []() {
        std::cout << "Timer executed after 2 seconds!" << std::endl;
    });

    // Wait for a while to see the timers execute
    std::this_thread::sleep_for(std::chrono::seconds(3));

    timer.stop();
    return 0;
}
