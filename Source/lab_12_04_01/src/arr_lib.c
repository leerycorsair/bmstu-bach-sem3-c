
#include "arr_lib.h"

#ifdef STATIC
void *arr_allocation(size_t arr_size)
#else
DLL void *DECL arr_allocation(size_t arr_size)
#endif
{
    return (int *)malloc(arr_size * sizeof(int));
}

#ifdef STATIC
void del_arr(int *arr)
#else
DLL void DECL del_arr(int *arr)
#endif
{
    if (arr != NULL)
        free(arr);
}

#ifdef STATIC
int key(const int *pb_src, const int *pe_src, int **pb_dst, int **pe_dst)
#else
DLL int DECL key(const int *pb_src, const int *pe_src, int **pb_dst, int **pe_dst)
#endif
{
    if ((pb_src == NULL) || (pe_src == NULL))
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
        if (elem_count > *pe_dst - *pb_dst)
            return elem_count;
        // *pb_dst = malloc(sizeof(int) * elem_count);
        // if (*pb_dst == NULL)
        //     return UNSUCCESSFUL_MEMORY_ALLOCATION;
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

#ifdef STATIC
int compare_int(const void *p, const void *q)
#else
DLL int DECL compare_int(const void *p, const void *q)
#endif
{
    return *(int *)p - *(int *)q;
}

#ifdef STATIC
void swap(void *a, void *b, size_t size)
#else
DLL void DECL swap(void *a, void *b, size_t size)
#endif
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

#ifdef STATIC
void mysort(void *base, size_t nmemb, size_t size, int (*compar)(const void *, const void *))
#else
DLL void DECL mysort(void *base, size_t nmemb, size_t size, int (*compar)(const void *, const void *))
#endif
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