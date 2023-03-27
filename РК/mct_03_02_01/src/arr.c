#include "arr.h"

int set_len(my_type **arr, size_t len)
{
    my_type *tmp = realloc(*arr, len * (sizeof(my_type)));
    if (tmp == NULL)
        return UNSUCCESSFUL_MEMORY_ALLOCATION;

    *arr = tmp;
    return SUCCESS;
}

int del_prime_indexes(my_type *arr, size_t *arr_size)
{
    size_t i = *arr_size - 1;
    size_t curr_index = *arr_size - 1;
    while (curr_index > 0)
    {
        if (is_prime(i))
        {
            for (size_t j = curr_index; j < *arr_size - 1; j++)
                arr[j] = arr[j + 1];
            *arr_size -= 1;
        }
        else
            curr_index--;
        i--;
    }
    return SUCCESS;
}

#define PRIME 1
#define NOT_PRIME 0
int is_prime(size_t num)
{
    for (size_t i = 0; i <= num / 2; i++)
        if (num % i == 0)
            return PRIME;
    return NOT_PRIME;
}