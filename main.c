#include <stdio.h>

#include "vec_int.h"

#define countof(x) (sizeof(x) / sizeof((x)[0]))

int main()
{
	VecInt* vec;
	{
		int arr[] = { 12, 1, 43, 29, 8, 74, 0, 7, 11 };
		vec = vec_int_create_from_array(100, countof(arr), arr);
	}

	printf("vec: ");
	vec_int_println(vec);

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
	vec_int_println(vec);

	VecInt *vec2;
	{
		int arr[] = { 9, 81, 12, 7, 57, 123, 26 };
		vec2 = vec_int_create_from_array(100, countof(arr), arr);
	}
	vec_int_msort(vec2);

	printf("vec2: ");
	vec_int_println(vec2);

	VecInt *merged = vec_int_merge(NULL, vec, vec2);

	printf("merged: ");
	vec_int_println(merged);

	bool is_sorted = vec_int_is_sorted(merged);
	if (is_sorted)
	{
		printf("merged is sorted\n");
	}
	else
	{
		printf("merged is not sorted\n");
	}

	VecInt* vec3 = vec_int_create_init(100, 5, 10, 20, 30, 40, 50);
	vec_int_println(vec3);

	return 0;
}
