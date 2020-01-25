CC=gcc
FLAGS= -Wall -c

all: frequency
frequency: main.o
	$(CC) -Wall -o frequency tree.o main.o
main.o: main.c
	$(CC) -Wall -c tree.c main.c
.PHONY: clean all

clean:
	rm -f *.o *.a frequency a.out
