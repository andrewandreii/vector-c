# C vectors

## Requirements for vector.c

`mcheck.h` - should be available on linux ([how to use mtrace?](https://en.wikipedia.org/wiki/Mtrace))

`stdio.h` `string.h` and `stdlib.h` - are most likely already on your machine

## How to test

```sh
make test
```

## How to build

```sh
make
```
or
```sh
make lib
```

## How to use

1) copy libvector.a and vector.h to your project

2) add this to your program
```c
#include "vector.h"
```

3) compile with the flags `-L. -lvector`

## Example code
run the code below with `make example`

```c
#include "vector.h"
#include <stdio.h>

void
main (void) {
	vec *v = vec_make(sizeof(int)); // make a vector that stores integers
	vec_reserve(v, 20); // reserve 20 * sizeof(int) bytes

	int i;
	for (i = 0; i < 20; ++ i) {
		vec_append(v, &i); // vec_append gets as an argument a void *
	}

	printf("the vector: ");
	for (i = 0; i < 20; ++ i) {
		printf("%d ", *(int *)vec_at(v, i)); // vec_at returns void * but we need an int
	}
	printf("\n");

	vec_free(v);
}

```

