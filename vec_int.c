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


int vec_int_size(VecInt* v) {
	return v->size;
}


int vec_int_capacity(VecInt* v) {
	return v->capacity;
}


void vec_int_clear(VecInt* v) {
	v->size = 0;
}


int vec_int_max(VecInt* v) {
	int max_sofar = v->ptr[0];
	for (int i = 1; i < v->size; ++i) {
		if (v->ptr[i] > max_sofar) {
			max_sofar = v->ptr[i];
		}
	}
	return max_sofar;
}


int vec_int_min(VecInt* v) {
	int min_sofar = v->ptr[0];
	for (int i = 1; i < v->size; ++i) {
		if (v->ptr[i] < min_sofar) {
			min_sofar = v->ptr[i];
		}
	}
	return min_sofar;
}


int vec_int_sum(VecInt* v) {
	int sum_sofar = 0;
	for (int i = 0; i < v->size; ++i) {
		sum_sofar += v->ptr[i];
	}
	return sum_sofar;
}


int vec_int_square_sum(VecInt* v) {
	int sum_sofar = 0;
	for (int i = 0; i < v->size; ++i) {
		sum_sofar += v->ptr[i] * v->ptr[i];
	}
	return sum_sofar;
}


void vec_int_qsort(VecInt* v) {
	if (v->size <= 1) {
		return;
	}
	int pivot_index = v->size / 2;
	int pivot = v->ptr[pivot_index];
	VecInt* a = vec_int_create(v->size);
	VecInt* b = vec_int_create(v->size);

	for (int i = 0; i < pivot_index; ++i) {
		if (v->ptr[i] < pivot) {
			vec_int_push_back(a, v->ptr[i]);
		} else {
			vec_int_push_back(b, v->ptr[i]);
		}
	}
	for (int i = pivot_index + 1; i < v->size; ++i) {
		if (v->ptr[i] < pivot) {
			vec_int_push_back(a, v->ptr[i]);
		} else {
			vec_int_push_back(b, v->ptr[i]);
		}
	}

	vec_int_qsort(a);
	vec_int_qsort(b);

	vec_int_clear(v);

	for (int i = 0; i < a->size; ++i) {
		vec_int_push_back(v, a->ptr[i]);
	}
	vec_int_push_back(v, pivot);
	for (int i = 0; i < b->size; ++i) {
		vec_int_push_back(v, b->ptr[i]);
	}

	vec_int_destroy(b);
	vec_int_destroy(a);
}


VecInt* vec_int_merge_sorted(VecInt* a, VecInt* b) {
	VecInt* v = vec_int_create(a->capacity + b->capacity);
	int i = 0;
	int j = 0;
	while (i < a->size && j < b->size) {
		while (i < a->size && a->ptr[i] <= b->ptr[j]) {
			vec_int_push_back(v, a->ptr[i]);
			++i;
		}
		while (j < b->size && a->ptr[i] >= b->ptr[j]) {
			vec_int_push_back(v, b->ptr[j]);
			++j;
		}
	}
	if (i < a->size) {
		for (; i < a->size; ++i) {
			vec_int_push_back(v, a->ptr[i]);
		}
	}
	if (j < a->size) {
		for (; j < b->size; ++j) {
			vec_int_push_back(v, b->ptr[j]);
		}
	}
	return v;
}
