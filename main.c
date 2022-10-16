#include <stdio.h>

#include "vec_int.h"


int main() {
	VecInt* vec = vec_int_create(1);
	for (int i = 0; i < 100; ++i) {
		vec_int_push_back(vec, i);
	}
	for (int i = 0; i < 100; ++i) {
		int ith = vec_int_get(vec, i);
		printf("%d\n", ith);
	}


	return 0;
}
