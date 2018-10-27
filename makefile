SHELL = /bin/bash
CC = g++
CFLAGS = `pkg-config opencv --cflags --libs`
SRC = shapefinder.c
OBJS = $(SRC:.c=.o)
all: test main

main: main.o $(OBJS)
	$(CC) -o $@ $^ $(CFLAGS)

shapefinder: shapefinder.o $(OBJS)
	$(CC) -o $@ $^ $(CFLAGS)

test: test.o $(OBJS)
	$(CC) -o $@ $^ $(CFLAGS)
	./test
	echo "Tests passed"

daemon:
	./continuous-make.sh

clean:
	rm test main *.o
