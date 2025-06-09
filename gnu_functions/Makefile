CXX         := g++
CXXFLAGS    := -std=c++17 -Wall -Wextra
LDFLAGS     :=

SOURCES := $(wildcard *.cpp)
EXES := $(SOURCES:.cpp=)

.PHONY: all clean

all: $(EXES)

# Rule for main: link main.o with the other object files (aligned_malloc.o, freq_finder.o, isAlphaBet.o, memcpy.o, strcmp.o, strcpy.o, strlen.o) so that symbols (aligned_free, aligned_malloc, freq_finder, isAlphaBet, m_memcpy, m_strcmp, m_strcpy, m_strlen) are available.
main: main.o aligned_malloc.o freq_finder.o isAlphaBet.o memcpy.o strcmp.o strcpy.o strlen.o
	$(CXX) $(CXXFLAGS) $^ -o $@ $(LDFLAGS)

# Rule for other executables (e.g. timer, isSpace, check_endiness, etc.) remains unchanged.
%: %.cpp
	$(CXX) $(CXXFLAGS) $< -o $@ $(LDFLAGS)

clean:
	rm -f $(EXES) *.o
