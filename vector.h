#ifndef VEC_C
#define VEC_C
#include <stdlib.h>
#include <string.h>

typedef struct {
	int elem_size;
	int capacity;
	int size;
	void **v;
} vec;
#define DEFAULT_SIZE 4

#define vec_front(v) v->v[0]
#define vec_back(v) v->v[v->size - 1]
#define vec_empty(v) (v->size == 0)

vec *vec_make (int elem_size);
#define vec_clear vec_free_v
void vec_free_v (vec *v);
void vec_free (vec *v);

void vec_erase (vec *v, int start, int end);
#define vec_reserve vec_realloc
void vec_realloc (vec *v, int new_cap);

#define VEC_SET    1
#define VEC_APPEND 2
#define VEC_INSERT 3
#define vec_set(v, data, idx)    vec_do(v, data, idx, VEC_SET)
#define vec_append(v, data)      vec_do(v, data, 0, VEC_APPEND)
#define vec_insert(v, data, idx) vec_do(v, data, idx, VEC_INSERT)
#define vec_push_back vec_append

void *vec_make_ptr (vec *v, void *data);

void vec_do (vec *v, void *data, int idx, int code);

void vec_set_ptr (vec *v, void *data, int idx);
void vec_append_ptr (vec *v, void *data);
void vec_insert_ptr (vec *v, void *data, int idx);
void vec_remove (vec *v, int idx);

void *vec_at (vec *v, int idx);
#define vec_shrink(v) vec_realloc(v, v->size);
/* void *vec_shrink (vec *v); */
void *vec_pop_back (vec *v);

void vec_assign (vec *v, vec *old_v);
void vec_swap (vec *v1, vec *v2);

#endif
