TARGET     	:= $(shell basename `pwd`)
CC			:= gcc
CFLAGS 		:= -I/usr/include/libxml2
LDFLAGS 	:= -L/usr/lib/x86_64-linux-gnu 
LDFLAGS 	+= -lxml2

.PHONY: all

$(TARGET): *.c
	$(CC) $(CFLAGS) $^ -o $@  $(LDFLAGS)

all: $(TARGET)

clean:
	rm -rf $(TARGET)
