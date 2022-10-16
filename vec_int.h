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

int vec_int_size(VecInt* v);

int vec_int_capacity(VecInt* v);

void vec_int_clear(VecInt* v);

int vec_int_max(VecInt* v);

int vec_int_min(VecInt* v);

int vec_int_sum(VecInt* v);

int vec_int_square_sum(VecInt* v);

void vec_int_qsort(VecInt* v);

void vec_int_merge_sorted(VecInt* merged, const VecInt* a, const VecInt* b);

void vec_int_msort(VecInt* v);
