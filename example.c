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
	int elem;
	for (i = 0; i < 20; ++ i) {
		vec_at(v, i, &elem);
		printf("%d ", elem); // vec_at returns void * but we need an int
	}
	printf("\n");

	vec_free(v);
}
