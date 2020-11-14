#include <stdio.h>
#include "vector.c"
#include <mcheck.h>

void
print (const char *c, int *n) {
	printf(c, *n);
}

void
print_vec (const char *c, vec *v) {
	int i = 0;
	printf(c);
	printf("size: %d\ncapacity: %d\n", v->size, v->capacity);
	while (i < v->size) {
		print("%d\n", vec_at(v, i));
		++ i;
	}
	printf("\n");
}

void
main (void) {
	mtrace();

	vec *v = vec_make(4);
	int elems[6] = { 1, 2, 3, 4, 5, 6 };
	vec_append(v, elems + 0);
	vec_append(v, elems + 1);
	vec_append(v, elems + 2);
	vec_append(v, elems + 3);
	vec_append(v, elems + 4);
	print_vec("5 elements appened:\n", v);

	vec_insert(v, elems + 5, 3);
	print_vec("elem 6 inserted:\n", v);

	vec_remove(v, 5);
	vec_remove(v, 1);
	vec_shrink(v);
	print_vec("shrinked and elements 5 and 1 removed:\n", v);

	vec_reserve(v, 10);
	print_vec("reserved:\n", v);

	vec *new_v = malloc(sizeof(vec));
	vec_assign(new_v, v);
	print_vec("new vector:\n", new_v);

	int *popped = vec_pop_back(v);
	print("popped = %d\n\n", popped);
	free(popped);

	vec_swap(v, new_v);
	printf("swapped:\n");
	print_vec("v =\n", v);
	print_vec("new_v =\n", new_v);

	vec_clear(new_v);
	print_vec("cleared new_v:\n", new_v);
	vec_free(new_v);

	vec_set(v, elems + 5, 0);
	print_vec("set idx 0 to elem + 5:\n", v);

	vec_erase(v, 0, 2);
	print_vec("erased from 0 to 2:\n", v);

	vec_free(v);

	muntrace();
}
