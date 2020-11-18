VECTOR_OUTPUT=libvector.a libvector.so

all: sharedobj staticlib man

manfile:
	ronn --roff man/vector.ronn

sharedobj: vector.c vector.h
	gcc -c -fpic vector.c
	gcc -shared -o libvector.so vector.o
	rm vector.o

staticlib: vector.c vector.h
	gcc -c vector.c
	ar -rcs libvector.a vector.o
	rm vector.o
	ranlib libvector.a

clean:
	rm -f ${VECTOR_OUTPUT} a.out
