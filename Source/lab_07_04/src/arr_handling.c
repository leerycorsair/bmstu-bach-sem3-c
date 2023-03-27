
#include "../inc/arr_handling.h"

void *arr_allocation(size_t size)
{
    return (int *)malloc(size * sizeof(int));
}

void del_arr(int *arr)
{
    if (arr != NULL)
        free(arr);
}

int key(const int *pb_src, const int *pe_src, int **pb_dst, int **pe_dst)
{
    if ((pb_src == NULL) || (pe_src == NULL) || (*pb_dst != NULL) || (*pe_dst != NULL))
        return FILTER_ERROR;

    double sum = 0.0;
    int *curr_pointer = (int *)pb_src;
    while (curr_pointer < pe_src)
    {
        sum += *curr_pointer;
        curr_pointer += 1;
    }
    sum = sum / (pe_src - pb_src);

    curr_pointer = (int *)pb_src;
    int elem_count = 0;
    while (curr_pointer < pe_src)
    {
        if (*curr_pointer > sum)
            elem_count += 1;
        curr_pointer += 1;
    }
    if (elem_count > 0)
    {
        *pb_dst = malloc(sizeof(int) * elem_count);
        if (*pb_dst == NULL)
            return UNSUCCESSFUL_MEMORY_ALLOCATION;
        *pe_dst = *pb_dst;

        curr_pointer = (int *)pb_src;
        while (curr_pointer < pe_src)
        {
            if (*curr_pointer > sum)
            {
                **pe_dst = *curr_pointer;
                *pe_dst += 1;
            }
            curr_pointer += 1;
        }
        if (pe_dst == pb_dst)
            return FILTER_ERROR;
        return SUCCESS;
    }
    else
        return FILTER_ERROR;
}

int compare_int(const void *p, const void *q)
{
    return *(int *)p - *(int *)q;
}

void swap(void *a, void *b, size_t size)
{
    char *pba = a;
    char *pbb = b;
    for (size_t i = 0; i < size; i++)
    {
        char tmp = *pba;
        *pba = *pbb;
        *pbb = tmp;
        pba += 1;
        pbb += 1;
    }
}

void mysort(void *base, size_t nmemb, size_t size, int (*compar)(const void *, const void *))
{
    char *pb = base;
    char *pe = pb + nmemb * size;
    for (size_t i = 0; i < nmemb && pe > pb; i++)
    {
        char *imax = pb;
        char *j = pb + size;
        while (j < pe)
        {
            if (compar(j, imax) > 0)
                imax = j;
            j += size;
        }
        pe -= size;
        swap(imax, pe, size);
    }
}