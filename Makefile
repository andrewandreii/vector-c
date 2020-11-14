dir = $(shell pwd)

all: lib

test:
	touch mtracedata
	export MALLOC_TRACE=${dir}/mtracedata
	gcc test.c -g
	./a.out
	mtrace a.out mtracedata

example: lib
	gcc example.c -L. -lvector
	./a.out

lib:
	gcc -c vector.c
	ar -rcs libvector.a vector.o
	ranlib libvector.a

clean:
	rm vector.o
	rm libvector.a
	rm mtracedata
	rm a.out
