#include "../inc/file_io.h"

int fread_arr(FILE *f, int *arr_bp, int **arr_ep)
{
    int tmp;
    int ec;
    *arr_ep = arr_bp;
    while (!feof(f))
    {
        if ((ec = fscanf(f, "%d", &tmp)) == 0 || ec == EOF)
            break;
        else
        {
            **arr_ep = tmp;
            *arr_ep += 1;
        }
    }
    if (*arr_ep == arr_bp)
        return INCORRECT_FILE_CONTENT;
    return SUCCESS;
}

int fget_arr_size(FILE *f, size_t *size)
{
    int tmp_num;
    while (!feof(f))
    {
        if (fscanf(f, "%d", &tmp_num) > 0)
            *size += 1;
        else
            break;
    }
    if (*size == 0 || !feof(f))
        return INCORRECT_FILE_CONTENT;

    return SUCCESS;
}

int fprintf_arr(FILE *f, int *arr_bp, int *arr_ep)
{
    int *curr_pointer = arr_bp;
    while (curr_pointer < arr_ep)
    {
        if (fprintf(f, "%d ", *curr_pointer) <= 0)
            return WRITING_ERROR;
        curr_pointer += 1;
    }
    return SUCCESS;
}