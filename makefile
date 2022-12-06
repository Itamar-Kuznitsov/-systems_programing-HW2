CC=gcc
FLAGS= -Wall -g

# compiling the whole program
all: my_mat.o main.o connections

# making the execusion file
connections: my_mat.o main.o
	$(CC) $(FLAGS) my_mat.o main.o -o connections


main: main.c my_mat.h
	$(CC) $(FLAGS) -c main.c

my_mat: my_mat.c my_mat.h
	$(CC) $(FLAGS) -c my_mat.c


.PHONY: clean make all

# deleting all .o + connections(exe) fills
clean:
	rm -f *.o connections
