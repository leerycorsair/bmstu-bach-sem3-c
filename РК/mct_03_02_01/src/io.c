#include "io.h"


int read_arr(my_type **arr, size_t arr_size)
{
    for (size_t i = 0; i < arr_size; i++)
        if (scanf(MY_SCANF, (*arr+i)) == 0)
            return READING_ERROR;
    return SUCCESS;
}

void print_arr(my_type *arr, size_t arr_size)
{
    for (size_t i = 0; i < arr_size; i++)
        printf(MY_PRINTF, arr[i]);
}