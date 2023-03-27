#ifndef ARR_H
#define ARR_h

#include "defines.h"
#include <stdlib.h>

int set_len(my_type **arr, size_t len);

int del_prime_indexes(my_type *arr, size_t *arr_size);

int is_prime(size_t num);

#endif