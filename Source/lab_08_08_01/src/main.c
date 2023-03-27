

#include <stdio.h>
#include <stdlib.h>

#include "err_codes.h"
#include "matrix_processing.h"

int main(void)
{
    setbuf(stdout, NULL);
    int matrix1_rows, matrix1_columns, matrix2_rows, matrix2_columns, *matrix1 = NULL, *matrix2 = NULL;

    if (scanf("%d%d", &matrix1_rows, &matrix1_columns) <= 1 || matrix1_columns <= 0 || matrix1_rows <= 0 ||
        (matrix1 = (int *)matrix_create(matrix1_rows, matrix1_columns, sizeof(int))) == NULL || read_matrix(matrix1_rows, matrix1_columns, matrix1) ||
        scanf("%d%d", &matrix2_rows, &matrix2_columns) <= 1 || matrix2_columns <= 0 || matrix2_rows <= 0 ||
        (matrix2 = matrix_create(matrix2_rows, matrix2_columns, sizeof(int))) == NULL || read_matrix(matrix2_rows, matrix2_columns, matrix2))
    {
        matrix_del(matrix1);
        matrix_del(matrix2);
        return MATRIX_CREATE_ERROR;
    }

    if (make_square_matrix(&matrix1, &matrix1_rows, &matrix1_columns) || make_square_matrix(&matrix2, &matrix2_rows, &matrix2_columns))
    {
        matrix_del(matrix1);
        matrix_del(matrix2);
        return UNSUCCESSFUL_MEMORY_ALLOCATION;
    }
    if (make_eq_size_matrix(&matrix1, &matrix1_rows, &matrix1_columns, &matrix2, &matrix2_rows, &matrix2_columns))
    {
        matrix_del(matrix1);
        matrix_del(matrix2);
        return UNSUCCESSFUL_MEMORY_ALLOCATION;
    }
    int matrix1_power, matrix2_power;
    if (scanf("%d%d", &matrix1_power, &matrix2_power) <= 1 || matrix1_power < 0 || matrix2_power < 0)
    {
        matrix_del(matrix1);
        matrix_del(matrix2);
        return POWER_READING_ERROR;
    }
    if (m_pow(&matrix1, &matrix1_rows, matrix1_power) || m_pow(&matrix2, &matrix2_rows, matrix2_power) || multi_matrix(&matrix1, &matrix1_rows, matrix2, &matrix2_rows))
    {
        matrix_del(matrix1);
        matrix_del(matrix2);
        return UNSUCCESSFUL_MEMORY_ALLOCATION;
    }
    print_matrix(matrix1, matrix1_rows, matrix1_rows);
    matrix_del(matrix1);
    matrix_del(matrix2);

    return SUCCESS;
}