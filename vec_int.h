#include <stdbool.h>

struct VecInt;
typedef struct VecInt VecInt;


VecInt* vec_int_create(int capacity);

void vec_int_destroy(VecInt* v);

void vec_int_push_back(VecInt* v, int a);

void vec_int_reserve(VecInt* v, int n);

int vec_int_get(VecInt* v, int i);

int vec_int_index(VecInt* v, int a);

bool vec_int_contains(VecInt* v, int a);
