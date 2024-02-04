CC=gcc
FLAGS=-Wall -g 
all : connections

connections: main.o my_mat.o
	$(CC) $(FLAGS) -o connections main.o my_mat.o

main.o: main.c my_mat.h
	$(CC) $(FLAGS) -c main.c 

my_mat.o: my_mat.h my_mat.c 
	$(CC) $(FLAGS) -fPIC -c my_mat.c 

clean: 
	rm *.o connections
 