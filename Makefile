all: lib

example: lib
	gcc example.c -L. -lvector
	./a.out

lib: vector.c vector.h
	gcc -c vector.c
	ar -rcs libvector.a vector.o
	ranlib libvector.a

clean:
	rm vector.o
	rm libvector.a
	rm mtracedata
	rm a.out
