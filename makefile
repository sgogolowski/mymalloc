all: memgrind.c mymalloc.o
	gcc memgrind.c mymalloc.o -o test
mymalloc.o: mymalloc.c
	gcc mymalloc.c -c
clean:
	rm test; rm mymalloc.o
