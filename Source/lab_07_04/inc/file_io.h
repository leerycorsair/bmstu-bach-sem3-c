#ifndef __FILE_IO_H__
#define __FILE_IO_H__

#include "err_codes.h"
#include "stdio.h"

int fget_arr_size(FILE *f, size_t *size);
int fread_arr(FILE *f, int *arr_bp, int **arr_ep);
int fprintf_arr(FILE *f, int *arr_bp, int *arr_ep);

#endif