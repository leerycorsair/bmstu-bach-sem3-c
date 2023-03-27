#ifndef __ARR_HANDLING_H__
#define __ARR_HANDLING_H__

#include <stdlib.h>
#include <stdio.h>
#include "err_codes.h"

void *arr_allocation(size_t arr_size);
void del_arr(int *arr);
int key(const int *pb_src, const int *pe_src, int **pb_dst, int **pe_dst);
void mysort(void *base, size_t nmemb, size_t size, int (*compar)(const void *, const void *));
int compare_int(const void *p, const void *q);
void swap(void *a, void *b, size_t size);

#endif