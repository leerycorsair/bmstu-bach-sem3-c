#ifndef __MATRIX_H__
#define __MATRIX_H__

#include <stdio.h>
#include "list.h"
#include "err_codes.h"

typedef struct
{
    int i;
    int j;
    int value;
} cell_t;

cell_t *cell_create(int i, int j, int value);
void cell_del(cell_t **cell);

int matrix_read(node_t **matrix);
int matrix_columns(node_t *matrix);
int matrix_rows(node_t *matrix);
int matrix_addition(node_t *matrix1, node_t *matrix2, node_t **matrix_res);
int matrix_value_by_pos(node_t *matrix, int row, int column);
int matrix_multiplication(node_t *matrix1, node_t *matrix2, node_t **matrix_res);
int matrix_find_row_with_max(node_t *matrix);

void matrix_del_max_row(node_t **matrix);
void matrix_print(node_t *matrix);

#endif //__MATRIX_H__