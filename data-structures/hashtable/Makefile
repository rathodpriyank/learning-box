TARGET     	:= $(shell basename `pwd`)
CC			:= gcc
LDFLAGS 	= #-L./lib 

.PHONY: all

$(TARGET): *.c
	$(CC) $(CFLAGS) $^ -o $@ $(LDFLAGS)

all: $(TARGET)

clean:
	rm -rf $(TARGET)
