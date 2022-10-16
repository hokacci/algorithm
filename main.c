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
	int min = vec_int_min(vec);
	int max = vec_int_max(vec);

	printf("min: %d\n", min);
	printf("max: %d\n", max);

	return 0;
}
