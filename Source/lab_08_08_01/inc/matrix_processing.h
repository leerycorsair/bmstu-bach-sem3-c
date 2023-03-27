#ifndef __MATRIX_PROCESSING_H__
#define __MATRIX_PROCESSING_H__

#include <stdio.h>
#include <math.h>
#include "err_codes.h"
#include <stdlib.h>
#include <string.h>

void *matrix_create(int rows, int columns, size_t elem_size);
int read_matrix(int rows, int columns, int *matrix);
void matrix_del(void *data);
int make_square_matrix(int **matrix, int *rows, int *columns);
int del_column(int **matrix, int *rows, int *columns);
int del_row(int **matrix, int *rows, int *columns);
int make_eq_size_matrix(int **matrix1, int *matrix1_rows, int *matrix1_columns, int **matrix2, int *matrix2_rows, int *matrix2_columns);
int add_row(int **matrix, int *matrix_rows, int *matrix_columns);
int add_column(int **matrix, int *matrix_rows, int *matrix_columns);
void print_matrix(int *matrix, int rows, int columns);
int multi_matrix(int **matrix1, int *matrix1_size, int *matrix2, int *matrix2_size);
int m_pow(int **matrix, int *size, int pow);

#endif