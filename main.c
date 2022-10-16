#include <stdio.h>

#include "vec_int.h"


int main() {

	VecInt* vec = vec_int_create(1);

	vec_int_push_back(vec, 12);
	vec_int_push_back(vec, 1);
	vec_int_push_back(vec, 43);
	vec_int_push_back(vec, 29);
	vec_int_push_back(vec, 8);
	vec_int_push_back(vec, 74);
	vec_int_push_back(vec, 0);
	vec_int_push_back(vec, 7);
	vec_int_push_back(vec, 11);

	int size = vec_int_size(vec);
	for (int i = 0; i < size; ++i) {
		int ith = vec_int_get(vec, i);
		printf("%d\n", ith);
	}
	int min = vec_int_min(vec);
	int max = vec_int_max(vec);
	int sum = vec_int_sum(vec);
	int square_sum = vec_int_square_sum(vec);

	printf("min: %d\n", min);
	printf("max: %d\n", max);
	printf("sum: %d\n", sum);
	printf("square_sum: %d\n", square_sum);

	vec_int_qsort(vec);

	printf("sorted\n");

	for (int i = 0; i < size; ++i) {
		int ith = vec_int_get(vec, i);
		printf("%d\n", ith);
	}

	return 0;
}
