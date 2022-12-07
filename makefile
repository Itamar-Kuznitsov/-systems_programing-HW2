CC=gcc
FLAGS= -Wall -g

# compiling the whole program
all: libmy_mat my_mat.o main.o connections

# making the execusion file
connections: main.o libmy_mat
	$(CC) $(FLAGS) my_mat.o main.o -o connections

libmy_mat: libmy_mat.so 

libmy_mat.so: main.o my_mat.o 
	$(CC) $(FLAGS) -shared -o ./libmy_mat.so main.o my_mat.o 


main.o: main.c my_mat.h
	$(CC) $(FLAGS) -fPIC -c main.c

my_mat.o: my_mat.c my_mat.h
	$(CC) $(FLAGS) -fPIC -c my_mat.c


.PHONY: clean make all

# deleting all .o + connections(exe) fills
clean:
	rm -f *.o *.so connections
