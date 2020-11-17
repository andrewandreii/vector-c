#ifndef VEC_C
#define VEC_C
#include <stdlib.h>
#include <string.h>

typedef struct {
	int elem_size;
	int capacity;
	int size;
	void *v;
} vec;
#define DEFAULT_SIZE 4
#define CAST(x, y) (x)y
#define TOADDR(v, x) x * v->elem_size

#define vec_front(v) v->v[0]
#define vec_empty(v) (v->size == 0)
#define vec_alloc malloc(sizeof(vec))

vec *vec_make (int elem_size);
vec *vec_from_ptr (int *l, int size);
#define vec_clear(v) v->size = 0
void vec_free (vec *v);

void vec_erase (vec *v, int start, int end);
#define vec_reserve vec_realloc
void vec_realloc (vec *v, int new_cap);

void vec_set (vec *v, int idx, void *data);
void vec_append (vec *v, void *data);
void vec_insert (vec *v, int idx, void *data);
void vec_remove (vec *v, int idx);

void vec_at (vec *v, int idx, void *ret);
#define vec_shrink(v) vec_realloc(v, v->size);
/* void *vec_shrink (vec *v); */
void vec_pop (vec *v, void *ret);

void vec_assign (vec *v1, vec *v2);
void vec_swap (vec *v1, vec *v2);

#endif
