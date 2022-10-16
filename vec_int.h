#include <stdbool.h>

struct VecInt;
typedef struct VecInt VecInt;


VecInt* vec_int_create(int capacity);

void vec_int_destroy(VecInt* v);

void vec_int_push_back(VecInt* v, int a);

void vec_int_reserve(VecInt* v, int n);

int vec_int_get(const VecInt* v, int i);

int vec_int_index(const VecInt* v, int a);

bool vec_int_contains(const VecInt* v, int a);

int vec_int_size(const VecInt* v);

int vec_int_capacity(const VecInt* v);

void vec_int_clear(VecInt* v);

int vec_int_max(const VecInt* v);

int vec_int_min(const VecInt* v);

int vec_int_sum(const VecInt* v);

int vec_int_square_sum(const VecInt* v);

void vec_int_qsort(VecInt* v);

VecInt* vec_int_merge(VecInt* merged, const VecInt* a, const VecInt* b);

void vec_int_msort(VecInt* v);

bool vec_int_is_sorted(const VecInt* v);
