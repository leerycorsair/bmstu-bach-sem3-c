#include "arr_lib.h"

DLL int DECL calc_fib(int order)
{
    if (order == 1)
        return 0;
    if (order == 2)
        return 1;
    int a = 0, b = 1, c;
    for (int i = 2; i < order; i++)
    {
        c = a + b;
        a = b;
        b = c;
    }
    return c;
}

#define MAX_FIB 47
DLL int DECL arr_fill_fib(int *arr, int size)
{
    if (size > MAX_FIB || arr == NULL)
        return INCORRECT_INPUT;
    for (int i = 0; i < size; i++)
        arr[i] = calc_fib(i + 1);
    return SUCCESS;
}

DLL int DECL del_duples(int *src, int src_size, int *dst, int dst_size)
{
    int *tmp_dst = malloc(sizeof(int) * src_size);
    int tmp_size = 0;
    for (int i = 0; i < src_size; i++)
    {
        int check = 1;
        for (int j = 0; j < tmp_size; j++)
            if (src[i] == tmp_dst[j])
            {
                check = 0;
                break;
            }
        if (check)
            tmp_dst[tmp_size++] = src[i];
    }
    if (dst == NULL || dst_size == 0)
    {
        free(tmp_dst);
        return tmp_size;
    }
    else
    {
        for (int i = 0; i < tmp_size; i++)
            dst[i] = tmp_dst[i];
        free(tmp_dst);
        return SUCCESS;
    }
}
