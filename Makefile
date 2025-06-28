CC = gcc
CFLAGS = -Wall -g

all: program

program: main.o algoritmos.o
	$(CC) $(CFLAGS) -o program main.o algoritmos.o

main.o: main.c algoritmos.h
	$(CC) $(CFLAGS) -c main.c

algoritmos.o: algoritmos.c algoritmos.h
	$(CC) $(CFLAGS) -c algoritmos.c

clean:
	rm -f *.o program
