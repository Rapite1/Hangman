CC = gcc
CFLAGS = -Wall --std=c99
OBJECTS = main.o my_string.o generic_vector.o my_tree.o

evil_hangman: $(OBJECTS)
	$(CC) $(CFLAGS) -o evil_hangman $(OBJECTS)

my_tree.o: my_tree.c
	$(CC) $(CFLAGS) -c my_tree.c -o my_tree.o

key_test: my_string.o generic_vector.o key_test.o
	$(CC) $(CFLAGS) -o key_test my_string.o generic_vector.o key_test.o
key_test.o: key_test.c
	$(CC) $(CFLAGS) -c key_test.c -o key_test.o

generic_vector.o: generic_vector.c
	$(CC) $(CFLAGS) -c generic_vector.c -o generic_vector.o
main.o: main.c
	$(CC) $(CFLAGS) -c main.c -o main.o
my_string.o: my_string.c
	$(CC) $(CFLAGS) -c my_string.c -o my_string.o

clean:
	rm evil_hangman key_test key_test.o my_tree.o $(OBJECTS)