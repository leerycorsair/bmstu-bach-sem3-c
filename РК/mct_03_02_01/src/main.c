#define __USE_MINGW_ANSI_STDIO
#include <stdlib.h>
#include <stdio.h>

#include "defines.h"
#include "io.h"
#include "arr.h"

int main(void)
{
    setbuf(stdout, NULL);

    size_t arr_size;
    if (scanf("%zu", &arr_size) == 0)
        return READING_ERROR;

    my_type *arr;
    arr = malloc(arr_size * sizeof(my_type));
    if (arr == NULL)
        return UNSUCCESSFUL_MEMORY_ALLOCATION;
    if (read_arr(&arr, arr_size))
    {
        free(arr);
        return READING_ERROR;
    }

    print_arr(arr, arr_size);

    del_prime_indexes(arr, &arr_size);
    
    if (set_len(&arr, arr_size))
    {
        free(arr);
        return UNSUCCESSFUL_MEMORY_ALLOCATION;
    }

    print_arr(arr, arr_size);

    free(arr);

    return SUCCESS;
}