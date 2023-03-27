#include "matrix.h"

cell_t *cell_create(int i, int j, int value)
{
    cell_t *tmp = malloc(sizeof(cell_t));
    if (!tmp)
        return NULL;
    else
    {
        tmp->i = i;
        tmp->j = j;
        tmp->value = value;
        return tmp;
    }
}

void cell_del(cell_t **cell)
{
    if (cell == NULL || *cell == NULL)
        return;
    free(*cell);
    *cell = NULL;
}

int matrix_read(node_t **matrix)
{
    int rows, columns;
    if (scanf("%d%d", &rows, &columns) != 2 || rows <= 0 || columns <= 0)
        return READING_ERROR;
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < columns; j++)
        {
            int cell_value;
            if (scanf("%d", &cell_value) != 1)
                return READING_ERROR;
            if (cell_value != 0)
            {
                cell_t *cell = cell_create(i, j, cell_value);
                if (!cell)
                    return UNSUCCESSFUL_MEMORY_ALLOCATION;
                node_t *node = node_create(cell);
                if (!node)
                {
                    cell_del(&cell);
                    return UNSUCCESSFUL_MEMORY_ALLOCATION;
                }
                list_push_back(matrix, node);
            }
        }
    return SUCCESS;
}
void matrix_print(node_t *matrix)
{
    while (matrix)
    {
        printf("%d %d %d ", ((cell_t *)(matrix->data))->i, ((cell_t *)(matrix->data))->j, ((cell_t *)(matrix->data))->value);
        matrix = matrix->next;
    }
}

int matrix_addition(node_t *matrix1, node_t *matrix2, node_t **matrix_res)
{
    while (matrix1 && matrix2)
    {
        if (((cell_t *)(matrix1->data))->i == ((cell_t *)(matrix2->data))->i && ((cell_t *)(matrix1->data))->j == ((cell_t *)(matrix2->data))->j)
        {
            if (((cell_t *)(matrix1->data))->value + ((cell_t *)(matrix2->data))->value != 0)
            {
                cell_t *cell = cell_create(((cell_t *)(matrix1->data))->i, ((cell_t *)(matrix1->data))->j, ((cell_t *)(matrix1->data))->value + ((cell_t *)(matrix2->data))->value);
                if (!cell)
                    return UNSUCCESSFUL_MEMORY_ALLOCATION;
                node_t *node = node_create(cell);
                if (!node)
                {
                    cell_del(&cell);
                    return UNSUCCESSFUL_MEMORY_ALLOCATION;
                }
                list_push_back(matrix_res, node);
            }
            matrix1 = matrix1->next;
            matrix2 = matrix2->next;
        }
        else if (((cell_t *)(matrix1->data))->i < ((cell_t *)(matrix2->data))->i)
        {
            cell_t *cell = cell_create(((cell_t *)(matrix1->data))->i, ((cell_t *)(matrix1->data))->j, ((cell_t *)(matrix1->data))->value);
            if (!cell)
                return UNSUCCESSFUL_MEMORY_ALLOCATION;
            node_t *node = node_create(cell);
            if (!node)
            {
                cell_del(&cell);
                return UNSUCCESSFUL_MEMORY_ALLOCATION;
            }
            list_push_back(matrix_res, node);
            matrix1 = matrix1->next;
        }
        else if (((cell_t *)(matrix1->data))->i > ((cell_t *)(matrix2->data))->i)
        {
            cell_t *cell = cell_create(((cell_t *)(matrix2->data))->i, ((cell_t *)(matrix2->data))->j, ((cell_t *)(matrix2->data))->value);
            if (!cell)
                return UNSUCCESSFUL_MEMORY_ALLOCATION;
            node_t *node = node_create(cell);
            if (!node)
            {
                cell_del(&cell);
                return UNSUCCESSFUL_MEMORY_ALLOCATION;
            }
            list_push_back(matrix_res, node);
            matrix2 = matrix2->next;
        }
        else if (((cell_t *)(matrix1->data))->i == ((cell_t *)(matrix2->data))->i)
        {
            if (((cell_t *)(matrix1->data))->j < ((cell_t *)(matrix2->data))->j)
            {
                cell_t *cell = cell_create(((cell_t *)(matrix1->data))->i, ((cell_t *)(matrix1->data))->j, ((cell_t *)(matrix1->data))->value);
                if (!cell)
                    return UNSUCCESSFUL_MEMORY_ALLOCATION;
                node_t *node = node_create(cell);
                if (!node)
                {
                    cell_del(&cell);
                    return UNSUCCESSFUL_MEMORY_ALLOCATION;
                }
                list_push_back(matrix_res, node);
                matrix1 = matrix1->next;
            }
            else
            {
                cell_t *cell = cell_create(((cell_t *)(matrix2->data))->i, ((cell_t *)(matrix2->data))->j, ((cell_t *)(matrix2->data))->value);
                if (!cell)
                    return UNSUCCESSFUL_MEMORY_ALLOCATION;
                node_t *node = node_create(cell);
                if (!node)
                {
                    cell_del(&cell);
                    return UNSUCCESSFUL_MEMORY_ALLOCATION;
                }
                list_push_back(matrix_res, node);
                matrix2 = matrix2->next;
            }
        }
    }
    while (matrix1)
    {
        cell_t *cell = cell_create(((cell_t *)(matrix1->data))->i, ((cell_t *)(matrix1->data))->j, ((cell_t *)(matrix1->data))->value);
        if (!cell)
            return UNSUCCESSFUL_MEMORY_ALLOCATION;
        node_t *node = node_create(cell);
        if (!node)
        {
            cell_del(&cell);
            return UNSUCCESSFUL_MEMORY_ALLOCATION;
        }
        list_push_back(matrix_res, node);
        matrix1 = matrix1->next;
    }
    while (matrix2)
    {
        cell_t *cell = cell_create(((cell_t *)(matrix2->data))->i, ((cell_t *)(matrix2->data))->j, ((cell_t *)(matrix2->data))->value);
        if (!cell)
            return UNSUCCESSFUL_MEMORY_ALLOCATION;
        node_t *node = node_create(cell);
        if (!node)
        {
            cell_del(&cell);
            return UNSUCCESSFUL_MEMORY_ALLOCATION;
        }
        list_push_back(matrix_res, node);
        matrix2 = matrix2->next;
    }
    return SUCCESS;
}

int matrix_rows(node_t *matrix)
{
    int rows = 0;
    while (matrix)
    {
        if (((cell_t *)(matrix->data))->i > rows)
            rows++;
        matrix = matrix->next;
    }
    return (rows + 1);
}

int matrix_columns(node_t *matrix)
{
    int columns = 0;
    while (matrix)
    {
        if (((cell_t *)(matrix->data))->j > columns)
            columns++;
        matrix = matrix->next;
    }
    return (columns + 1);
}

int matrix_value_by_pos(node_t *matrix, int row, int column)
{
    while (matrix)
    {
        if (((cell_t *)(matrix->data))->i == row && ((cell_t *)(matrix->data))->j == column)
            return ((cell_t *)(matrix->data))->value;
        matrix = matrix->next;
    }
    return 0;
}

int matrix_multiplication(node_t *matrix1, node_t *matrix2, node_t **matrix_res)
{
    int rows1 = matrix_rows(matrix1);
    int columns1 = matrix_columns(matrix1);
    int columns2 = matrix_columns(matrix2);
    for (int i = 0; i < rows1; i++)
        for (int j = 0; j < columns2; j++)
        {
            int sum = 0;
            for (int k = 0; k < columns1; k++)
                sum += matrix_value_by_pos(matrix1, i, k) * matrix_value_by_pos(matrix2, k, j);
            if (sum)
            {
                cell_t *cell = cell_create(i, j, sum);
                if (!cell)
                    return UNSUCCESSFUL_MEMORY_ALLOCATION;
                node_t *node = node_create(cell);
                if (!node)
                {
                    cell_del(&cell);
                    return UNSUCCESSFUL_MEMORY_ALLOCATION;
                }
                list_push_back(matrix_res, node);
            }
        }
    return SUCCESS;
}

int matrix_find_row_with_max(node_t *matrix)
{
    int row_i = ((cell_t *)(matrix->data))->i;
    int max_value = ((cell_t *)(matrix->data))->value;
    while (matrix)
    {
        if (((cell_t *)(matrix->data))->value > max_value)
        {
            max_value = ((cell_t *)(matrix->data))->value;
            row_i = ((cell_t *)(matrix->data))->i;
        }
        matrix = matrix->next;
    }
    return row_i;
}

void matrix_del_max_row(node_t **matrix)
{
    int row_del = matrix_find_row_with_max(*matrix);
    while ((*matrix) && ((cell_t *)((*matrix)->data))->i == row_del)
    {
        node_t *next = (*matrix)->next;
        node_del(matrix);
        *matrix = next;
    }
    if (*matrix == NULL)
        return;
    node_t *curr = *matrix;
    while (curr->next)
        if (((cell_t *)(curr->next->data))->i == row_del)
        {
            node_t *next = curr->next->next;
            node_del(&curr->next);
            curr->next = next;
        }
        else
            curr = curr->next;
}