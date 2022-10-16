#include <stdlib.h>

#include "vec_int.h"

struct VecInt {
	int size;
	int capacity;
	int* ptr;
};


VecInt* vec_int_create(int capacity) {
	VecInt* v = malloc(sizeof(VecInt));
	v->size = 0;
	v->capacity = capacity;
	v->ptr = (int*)malloc(capacity * sizeof(int));
	return v;
}


void vec_int_destroy(VecInt* v) {
	free(v->ptr);
	free(v);
}


void vec_int_push_back(VecInt* v, int a) {
	if (v->size + 1 > v->capacity) {
		v->capacity *= 2;
		v->ptr = (int*)realloc(v->ptr, v->capacity * sizeof(int));
	}
	v->ptr[v->size] = a;
	v->size++;
}


void vec_int_reserve(VecInt* v, int n) {
	if (n <= v->capacity) {
		return;
	}
	while (n > v->capacity) {
		v->capacity *= 2;
	}
	v->ptr = (int*)realloc(v->ptr, v->capacity * sizeof(int));
}


int vec_int_get(VecInt* v, int i) {
	return v->ptr[i];
}


int vec_int_index(VecInt* v, int a) {
	for (int i = 0; i < v->size; ++i) {
		if (v->ptr[i] == a) {
			return i;
		}
	}
	return -1;
}

bool vec_int_contains(VecInt* v, int a) {
	for (int i = 0; i < v->size; ++i) {
		if (v->ptr[i] == a) {
			return true;
		}
	}
	return false;
}
