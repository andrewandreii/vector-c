#include "vector.h"
#include <stdio.h>

vec *
vec_make (int elem_size) {
	vec *v = vec_alloc;
	v->v = malloc(elem_size * DEFAULT_SIZE);
	v->capacity = DEFAULT_SIZE;
	v->elem_size = elem_size;
	return v;
}

vec *
vec_use_ptr (void *l, int size, int elem_size) {
	vec *v = vec_alloc;
	v->v = l;
	v->capacity = v->size = size;
	v->elem_size = elem_size;
	return v;
}

vec *
vec_from_ptr (void *l, int size, int elem_size) {
	vec *v = vec_alloc;
	v->v = malloc(elem_size * size);
	v->capacity = v->size = size;
	v->elem_size = elem_size;
	memcpy(v->v, l, TOADDR(v, v->size));
	return v;
}

void
vec_free (vec *v) {
	free(v->v);
	free(v);
}

void
vec_realloc (vec *v, int new_cap) {
	v->v = realloc(v->v, new_cap * v->elem_size);
	v->capacity = new_cap;
}

void
vec_erase (vec *v, int start, int end) {
	memmove(v->v + TOADDR(v, start), v->v + TOADDR(v, end), TOADDR(v, (v->size - end)));
	v->size -= start + end;
}

void
vec_pop (vec *v, void *ret) {
	memcpy(ret, v->v + TOADDR(v, v->size - 1), v->elem_size);
	/* memcpy(ret, v->v + (v->size - 1) * v->elem_size, v->elem_size); */
	vec_remove(v, v->size - 1);
}

void
vec_at (vec *v, int idx, void *ret) {
	memcpy(ret, v->v + TOADDR(v, idx), v->elem_size);
	/* memcpy(ret, v->v + idx * v->elem_size, v->elem_size); */
}

void
vec_set (vec *v, int idx, void *data) {
	memcpy(v->v + TOADDR(v, idx), data, v->elem_size);
	/* memcpy(v->v + idx * v->elem_size, data, v->elem_size); */
}

void
vec_insert (vec *v, int idx, void *data) {
	if (v->size == v->capacity) {
		vec_realloc(v, v->capacity + DEFAULT_SIZE);
	}

	memmove(v->v + TOADDR(v, idx + 1), v->v + TOADDR(v, idx), TOADDR(v, v->size - idx));
	/* memmove(v->v + (idx + 1) * v->elem_size, v->v + idx * v->elem_size, v->elem_size * (v->size - idx)); */
	memcpy(v->v + TOADDR(v, idx), data, v->elem_size);
	/* memcpy(v->v + idx * v->elem_size, data, v->elem_size); */
	++ v->size;
}

void
vec_append (vec *v, void *data) {
	if (v->size == v->capacity) {
		vec_realloc(v, v->capacity + DEFAULT_SIZE);
	}

	memcpy(v->v + TOADDR(v, v->size), data, v->elem_size);
	/* memcpy(v->v + v->size * v->elem_size, data, v->elem_size); */
	++ v->size;
}

void
vec_remove (vec *v, int idx) {
	memmove(v->v + TOADDR(v, idx), v->v + TOADDR(v, idx + 1), TOADDR(v, v->size - idx));
	/* memmove(v->v + idx * v->elem_size, v->v + (idx + 1) * v->elem_size, v->elem_size * (v->size - idx)); */
	-- v->size;
}

void
vec_swap (vec *v1, vec *v2) {
	vec *tmp = malloc(sizeof(vec));
	memcpy(tmp, v1, sizeof(vec));
	memcpy(v1, v2, sizeof(vec));
	memcpy(v2, tmp, sizeof(vec));
	free(tmp);
}

void
vec_assign (vec *v1, vec *v2) {
	v1->elem_size = v2->elem_size;
	v1->capacity = v2->capacity;
	v1->size = v2->size;
	v1->v = malloc(v1->capacity * v1->elem_size);
	memcpy(v1->v, v2->v, TOADDR(v1, v1->capacity));
}
