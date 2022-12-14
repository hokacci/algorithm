#include <stdio.h>

#include "vec_int.h"

int main()
{

	VecInt *vec = vec_int_create(1);

	vec_int_push_back(vec, 12);
	vec_int_push_back(vec, 1);
	vec_int_push_back(vec, 43);
	vec_int_push_back(vec, 29);
	vec_int_push_back(vec, 8);
	vec_int_push_back(vec, 74);
	vec_int_push_back(vec, 0);
	vec_int_push_back(vec, 7);
	vec_int_push_back(vec, 11);

	printf("vec: ");
	vec_int_print(vec);
	putchar('\n');

	int min = vec_int_min(vec);
	int max = vec_int_max(vec);
	int sum = vec_int_sum(vec);
	int square_sum = vec_int_square_sum(vec);

	printf("min: %d\n", min);
	printf("max: %d\n", max);
	printf("sum: %d\n", sum);
	printf("square_sum: %d\n", square_sum);

	vec_int_qsort(vec);

	printf("sorted: ");
	vec_int_print(vec);
	putchar('\n');

	VecInt *vec2 = vec_int_create(1);
	vec_int_push_back(vec2, 9);
	vec_int_push_back(vec2, 81);
	vec_int_push_back(vec2, 12);
	vec_int_push_back(vec2, 7);
	vec_int_push_back(vec2, 57);
	vec_int_push_back(vec2, 123);
	vec_int_push_back(vec2, 26);

	vec_int_msort(vec2);

	printf("vec2: ");
	vec_int_print(vec2);
	putchar('\n');

	VecInt *merged = vec_int_merge(NULL, vec, vec2);

	printf("merged: ");
	vec_int_print(merged);
	putchar('\n');

	bool is_sorted = vec_int_is_sorted(merged);
	if (is_sorted)
	{
		printf("merged is sorted\n");
	}
	else
	{
		printf("merged is not sorted\n");
	}

	return 0;
}
