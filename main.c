#include <stdio.h>

#include "vec_int.h"


int main() {

	VecInt* vec = vec_int_create(1);

	for (int i = 0; i < 100000; ++i) {
		vec_int_push_back(vec, i);
	}

	int size = vec_int_size(vec);
	for (int i = 0; i < size; ++i) {
		int ith = vec_int_get(vec, i);
		printf("%d\n", ith);
	}

	return 0;
}
