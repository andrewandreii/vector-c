#ifndef VEC
#define VEC

#include <stdlib.h>
#include <string.h>
#define DEFAULT_SIZE 4

typedef struct {
	int elem_size;
	int capacity;
	int size;
	void **v;
} vec;

#define vec_front(v) v->v[0]
#define vec_back(v) v->v[v->size - 1]
#define vec_empty(v) (v->size == 0)

vec *
vec_make (int elem_size) {
	vec *v = malloc(sizeof(vec));
	v->v = malloc(sizeof(void *) * DEFAULT_SIZE);
	v->capacity = DEFAULT_SIZE;
	v->elem_size = elem_size;
}

#define vec_clear vec_free_v
void
vec_free_v (vec *v) {
	int i = 0;
	while (i < v->size) {
		free(v->v[i]);
		++ i;
	}
	v->size = 0;
}

void
vec_free (vec *v) {
	vec_free_v(v);
	free(v->v);
	free(v);
}

void
vec_erase (vec *v, int start, int end) {
	memmove(v->v + start, v->v + end, (v->size - end) * sizeof(void *));
	v->size = v->size - (end - start);
}

#define vec_reserve vec_realloc
void
vec_realloc (vec *v, int new_cap) {
	v->v = realloc(v->v, sizeof(void *) * new_cap);
	v->capacity = new_cap;
}

#define VEC_SET    1
#define VEC_APPEND 2
#define VEC_INSERT 3
#define vec_set(v, data, idx)    vec_do(v, data, idx, VEC_SET)
#define vec_append(v, data)      vec_do(v, data, 0, VEC_APPEND)
#define vec_insert(v, data, idx) vec_do(v, data, idx, VEC_INSERT)
#define vec_push_back vec_append

// copy a void * to another void *
void *
vec_make_ptr (vec *v, void *data) {
	void *new_ptr = malloc(v->elem_size);
	memcpy(new_ptr, data, v->elem_size);
	return new_ptr;
}

#define vec_set_ptr(v, data, idx) v->v[idx] = data
/* void vec_set_ptr(vec *v, void *data, int idx); */
void vec_append_ptr(vec *v, void *data);
void vec_insert_ptr(vec *v, void *data, int idx);

void
vec_do (vec *v, void *data, int idx, int code) {
	void *new_ptr = vec_make_ptr(v, data);

	switch (code) {
		case VEC_SET:
			vec_set_ptr(v, new_ptr, idx); break;
		case VEC_APPEND:
			vec_append_ptr(v, new_ptr); break;
		case VEC_INSERT:
			vec_insert_ptr(v, new_ptr, idx); break;
	}
}

void
vec_append_ptr (vec *v, void *data) {
	if (v->size == v->capacity) {
		vec_realloc(v, v->capacity + DEFAULT_SIZE);
	}

	v->v[v->size] = data;
	++ v->size;
}


void
vec_insert_ptr (vec *v, void *data, int idx) {
	if (v->size == v->capacity) {
		vec_realloc(v, v->capacity + DEFAULT_SIZE);
	}

	int i = v->size;
	while (i >= idx) {
		v->v[i + 1] = v->v[i];
		-- i;
	}

	v->v[idx] = data;
	++ v->size;
}

void
vec_remove (vec *v, int idx) {
	free(v->v[idx]);
	int i = idx;
	while (i < v->size - 1) {
		v->v[i] = v->v[i + 1];
		++ i;
	}
	-- v->size;
}

void *
vec_at (vec *v, int idx) {
	if (idx > v->size) {
		return NULL;
	}

	return v->v[idx];
}

#define vec_shrink(v) vec_realloc(v, v->size);
/* void */
/* vec_shrink (vec *v) { */
/* 	vec_realloc(v, v->size); */
/* } */

void
vec_assign (vec *v, vec *old_v) {
	int i = 0;
	while (i < v->size) {
		free(v->v[i]);
		++ i;
	}
	free(v->v);

	v->elem_size = old_v->elem_size;
	v->capacity = old_v->capacity;
	v->v = malloc(sizeof(void *) * v->capacity);

	i = 0;
	while (i < old_v->size) {
		vec_append(v, old_v->v[i]);
		++ i;
	}
}

void *
vec_pop_back (vec *v) {
	void *back = malloc(v->elem_size);
	memcpy(back, vec_back(v), v->elem_size);
	vec_remove(v, v->size - 1);
	return back;
}

void
vec_swap (vec *v1, vec *v2) {
	vec *tmp = malloc(sizeof(vec));
	memmove(tmp, v1, sizeof(vec));
	memmove(v1, v2, sizeof(vec));
	memmove(v2, tmp, sizeof(vec));
	free(tmp);
}

#endif