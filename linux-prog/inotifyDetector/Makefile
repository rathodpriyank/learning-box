TARGET     	:= $(shell basename `pwd`)
CC			:= gcc
LDFLAGS 	= #-L./lib 

.PHONY: all

$(TARGET): *.c
	$(CC) $(CFLAGS) $(LDFLAGS) $^ -o $@

all: $(TARGET)

clean:
	rm -rf $(TARGET)

