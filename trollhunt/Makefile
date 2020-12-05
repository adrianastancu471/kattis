INCL_DIR := ../utils
CC := gcc
LIB := -lm
CFLAGS := -g -Wall -I$(INCL_DIR)

SOURCES := $(wildcard *.c $(INCL_DIR)/*.c)
OBJECTS := $(patsubst %.c, %.o, $(SOURCES))

all: main

main: $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) -o $@.elf $(LIB)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean: 
	rm -rf *.o
	rm -rf $(INCL_DIR)/*.o
	rm -rf main.elf