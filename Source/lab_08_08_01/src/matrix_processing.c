#include "matrix_processing.h"

void *matrix_create(int rows, int columns, size_t elem_size)
{
    return malloc(rows * columns * elem_size);
}

void matrix_del(void *data)
{
    if (data != NULL)
        free(data);
}

int read_matrix(int rows, int columns, int *matrix)
{
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < columns; j++)
            if (scanf("%d", (matrix + i * columns + j)) <= 0)
                return MATRIX_CREATE_ERROR;
    return SUCCESS;
}

int make_square_matrix(int **matrix, int *rows, int *columns)
{
    while (*rows != *columns)
        if (*rows > *columns)
        {
            if (del_row(matrix, rows, columns))
                return UNSUCCESSFUL_MEMORY_ALLOCATION;
        }
        else
        {
            if (del_column(matrix, rows, columns))
                return UNSUCCESSFUL_MEMORY_ALLOCATION;
        }
    return SUCCESS;
}

int del_row(int **matrix, int *rows, int *columns)
{
    int row_i;
    int min = **matrix;
    for (int i = 0; i < *columns; i++)
        for (int j = 0; j < *rows; j++)
            if (*(*matrix + j * (*columns) + i) <= min)
            {
                min = *(*matrix + j * (*columns) + i);
                row_i = j;
            }

    if (row_i != *rows - 1)
        for (int i = row_i; i < *rows - 1; i++)
            for (int j = 0; j < *columns; j++)
                *(*matrix + i * (*columns) + j) = *(*matrix + (i + 1) * (*columns) + j);
    *rows -= 1;
    int *ptmp = realloc(*matrix, (*rows) * (*columns) * sizeof(int));
    if (ptmp != NULL)
    {
        *matrix = ptmp;
        return SUCCESS;
    }
    else
        return UNSUCCESSFUL_MEMORY_ALLOCATION;
}

int del_column(int **matrix, int *rows, int *columns)
{
    int column_i;
    int min = **matrix;
    for (int i = 0; i < *columns; i++)
        for (int j = 0; j < *rows; j++)
            if (*(*matrix + j * (*columns) + i) <= min)
            {
                min = *(*matrix + j * (*columns) + i);
                column_i = i;
            }
    for (int i = 0; i < *rows; i++)
        for (int j = 0; j < *columns; j++)
            if (j != column_i)
                *(*matrix + i * (*columns) + j - i - (j > column_i)) = *(*matrix + i * (*columns) + j);
    *columns -= 1;
    int *ptmp = realloc(*matrix, (*rows) * (*columns) * sizeof(int));
    if (ptmp != NULL)
    {
        *matrix = ptmp;
        return SUCCESS;
    }
    else
        return UNSUCCESSFUL_MEMORY_ALLOCATION;
}

int make_eq_size_matrix(int **matrix1, int *matrix1_rows, int *matrix1_columns, int **matrix2, int *matrix2_rows, int *matrix2_columns)
{
    while (*matrix1_rows != *matrix2_rows)
        if (*matrix1_rows > *matrix2_rows)
        {
            if (add_row(matrix2, matrix2_rows, matrix2_columns))
                return UNSUCCESSFUL_MEMORY_ALLOCATION;
        }
        else
        {
            if (add_row(matrix1, matrix1_rows, matrix1_columns))
                return UNSUCCESSFUL_MEMORY_ALLOCATION;
        }
    while (*matrix1_columns != *matrix2_columns)
        if (*matrix1_columns > *matrix2_columns)
        {
            if (add_column(matrix2, matrix2_rows, matrix2_columns))
                return UNSUCCESSFUL_MEMORY_ALLOCATION;
        }
        else
        {

            if (add_column(matrix1, matrix1_rows, matrix1_columns))
                return UNSUCCESSFUL_MEMORY_ALLOCATION;
        }
    return SUCCESS;
}

int add_row(int **matrix, int *matrix_rows, int *matrix_columns)
{
    int *ptmp = realloc(*matrix, (*matrix_rows + 1) * (*matrix_columns) * sizeof(int));
    if (ptmp == NULL)
        return UNSUCCESSFUL_MEMORY_ALLOCATION;
    *matrix = ptmp;
    *matrix_rows += 1;
    double gm, power = (double)1 / (*matrix_rows - 1);
    for (int i = 0; i < *matrix_columns; i++)
    {
        gm = 1;
        for (int j = 0; j < *matrix_rows - 1; j++)
            gm *= *(ptmp + j * (*matrix_columns) + i);
        *(ptmp + (*matrix_rows - 1) * (*matrix_columns) + i) = (int)floor(pow(fabs(gm), power));
    }
    return SUCCESS;
}

int add_column(int **matrix, int *matrix_rows, int *matrix_columns)
{
    int *ptmp = realloc(*matrix, (*matrix_rows) * (*matrix_columns + 1) * sizeof(int));
    if (ptmp == NULL)
        return UNSUCCESSFUL_MEMORY_ALLOCATION;
    *matrix = ptmp;
    *matrix_columns += 1;
    for (int i = *matrix_rows - 1; i > -1; i--)
        for (int j = *matrix_columns - 2; j > -1; j--)
            *(*matrix + i * (*matrix_columns) + j) = *(*matrix + i * (*matrix_columns) + j - i);
    int min;
    for (int i = 0; i < *matrix_rows; i++)
    {
        min = *(*matrix + i * (*matrix_columns));
        for (int j = 0; j < *matrix_columns - 1; j++)
            if ((*(*matrix + i * (*matrix_columns) + j) < min))
                min = *(*matrix + i * (*matrix_columns) + j);
        *(*matrix + i * (*matrix_columns) + *matrix_columns - 1) = min;
    }
    return SUCCESS;
}

void print_matrix(int *matrix, int rows, int columns)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
            printf("%d ", *(matrix + i * (columns) + j));
        printf("\n");
    }
}

int multi_matrix(int **matrix1, int *matrix1_size, int *matrix2, int *matrix2_size)
{
    int *res = calloc(*matrix1_size * (*matrix1_size), sizeof(int));
    if (*matrix1 == NULL || matrix2 == NULL || res == NULL)
    {
        matrix_del(res);
        return UNSUCCESSFUL_MEMORY_ALLOCATION;
    }
    for (int i = 0; i < *matrix1_size; i++)
        for (int j = 0; j < *matrix2_size; j++)
            for (int k = 0; k < *matrix1_size; k++)
                *(res + i * (*matrix1_size) + j) += (*(*matrix1 + i * (*matrix1_size) + k)) * (*(matrix2 + k * (*matrix2_size) + j));
    matrix_del(*matrix1);
    *matrix1 = res;
    int check = 0;
    for (int i = 0; i < *matrix1_size; i++)
        for (int j = 0; i < *matrix1_size; i++)
            if (*(*matrix1 + i * (*matrix1_size) + j) != 0)
                check = 1;
    if (check == 0)
    {
        matrix_del(*matrix1);
        *matrix1 = calloc(1, sizeof(int));
        *matrix1_size = 1;
    }
    return SUCCESS;
}

int m_pow(int **matrix, int *size, int pow)
{
    if (pow == 0)
    {
        matrix_del(*matrix);
        if ((*matrix = calloc(*size * (*size), sizeof(int))) == NULL)
            return UNSUCCESSFUL_MEMORY_ALLOCATION;
        for (int i = 0; i < *size; i++)
            *(*matrix + i * (*size) + i) = 1;
        return SUCCESS;
    }
    if (pow > 1)
    {
        int *tmp = realloc(NULL, *size * (*size) * sizeof(int));
        memmove(tmp, *matrix, *size * (*size) * sizeof(int));
        for (int i = 0; i < pow - 1; i++)
            multi_matrix(matrix, size, tmp, size);
        matrix_del(tmp);
    }
    return SUCCESS;
}