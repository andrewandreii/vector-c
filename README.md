# C vectors

## Requirements for vector.c

**vector.c is just for testing and understanding better how the code in vector.h runs**

`mcheck.h` - should be available on linux ([how to use mtrace?](https://en.wikipedia.org/wiki/Mtrace))

`stdio.h` - should be available

---

**vector.h is the actual code that implements vectors**

`string.h` and `stdlib.h` - are most likely already on your machine

## How to test

```bash
gcc -g vector.c
./a.out
touch mtraceoutput
mtrace a.out mtraceoutput # checks for memory leaks
```

## How to use

copy `vector.h` in what folder you want to use it and include it
```bash
cp $PATH_TO_REPO/vector.h $PATH_TO_YOUR_PROJECT
```

and

```c
#include "vector.h"
```

## Example code
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

