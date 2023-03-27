
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "err_codes.h"
#include "file_io_lib.h"
#include "arr_lib.h"
#include <windows.h>

typedef void *(__cdecl *arr_allocation_t)(size_t arr_size);
typedef void(__cdecl *del_arr_t)(int *arr);
typedef void(__cdecl *mysort_t)(void *base, size_t nmemb, size_t size, int (*compar)(const void *, const void *));
typedef void(__cdecl *swap_t)(void *a, void *b, size_t size);
typedef int(__cdecl *key_t)(const int *pb_src, const int *pe_src, int **pb_dst, int **pe_dst);
typedef int(__cdecl *compare_int_t)(const void *p, const void *q);
typedef int(__cdecl *fget_arr_size_t)(FILE *f, size_t *size);
typedef int(__cdecl *fread_arr_t)(FILE *f, int *arr_bp, int **arr_ep);
typedef int(__cdecl *fprintf_arr_t)(FILE *f, int *arr_bp, int *arr_ep);

typedef struct
{
    arr_allocation_t arr_allocation;
    del_arr_t del_arr;
    mysort_t mysort;
    key_t key;
    compare_int_t compare_int;
    fget_arr_size_t fget_arr_size;
    fread_arr_t fread_arr;
    fprintf_arr_t fprintf_arr;
} funcs_t;

int main(int argc, char **argv)
{
#ifdef DYN_EXPORT
    HMODULE arr_lib;
    arr_lib = LoadLibrary("dlarr.dll");
    if (!arr_lib)
        return LIB_ERROR;
    HMODULE file_io_lib;
    file_io_lib = LoadLibrary("dlfile_io.dll");
    if (!file_io_lib)
    {
        FreeLibrary(arr_lib);
        return LIB_ERROR;
    }
    funcs_t func;
    func.arr_allocation = (arr_allocation_t)GetProcAddress(arr_lib, "arr_allocation");
    func.del_arr = (del_arr_t)GetProcAddress(arr_lib, "del_arr");
    func.mysort = (mysort_t)GetProcAddress(arr_lib, "mysort");
    func.key = (key_t)GetProcAddress(arr_lib, "key");
    func.compare_int = (compare_int_t)GetProcAddress(arr_lib, "compare_int");
    func.fget_arr_size = (fget_arr_size_t)GetProcAddress(file_io_lib, "fget_arr_size");
    func.fread_arr = (fread_arr_t)GetProcAddress(file_io_lib, "fread_arr");
    func.fprintf_arr = (fprintf_arr_t)GetProcAddress(file_io_lib, "fprintf_arr");
#else
    funcs_t func;
    func.arr_allocation = arr_allocation;
    func.del_arr = del_arr;
    func.mysort = mysort;
    func.key = key;
    func.compare_int = compare_int;
    func.fget_arr_size = fget_arr_size;
    func.fread_arr = fread_arr;
    func.fprintf_arr = fprintf_arr;
#endif
    setbuf(stdout, NULL);

    if (argc == 3 || (argc == 4 && strcmp(argv[3], "f") == 0))
    {
        FILE *f_in = fopen(argv[1], "r");
        if (f_in == NULL)
        {
#ifdef DYN_EXPORT
            FreeLibrary(arr_lib);
            FreeLibrary(file_io_lib);
#endif
            return NO_IN_FILE;
        }

        size_t arr_size = 0;
        if (func.fget_arr_size(f_in, &arr_size) || arr_size == 0)
        {
            fclose(f_in);
#ifdef DYN_EXPORT
            FreeLibrary(arr_lib);
            FreeLibrary(file_io_lib);
#endif
            return INCORRECT_FILE_CONTENT;
        }

        fclose(f_in);
        int *arr_bp = NULL, *arr_ep = NULL;
        if ((arr_bp = func.arr_allocation(arr_size)) == NULL)
        {
#ifdef DYN_EXPORT
            FreeLibrary(arr_lib);
            FreeLibrary(file_io_lib);
#endif
            return UNSUCCESSFUL_MEMORY_ALLOCATION;
        }

        f_in = fopen(argv[1], "r");
        func.fread_arr(f_in, arr_bp, &arr_ep);
        fclose(f_in);

        FILE *f_out = fopen(argv[2], "w");
        if (f_out == NULL)
        {
            func.del_arr(arr_bp);
#ifdef DYN_EXPORT
            FreeLibrary(arr_lib);
            FreeLibrary(file_io_lib);
#endif
            return OUT_FILE_ERROR;
        }
        if (argc == 4)
        {
            int *filtered_arr_bp = NULL, *filtered_arr_ep = NULL;
            int e_c = func.key(arr_bp, arr_ep, &filtered_arr_bp, &filtered_arr_ep);
            if (e_c < 0)
            {
                fclose(f_out);
                func.del_arr(arr_bp);
#ifdef DYN_EXPORT
                FreeLibrary(arr_lib);
                FreeLibrary(file_io_lib);
#endif
                return FILTER_ERROR;
            }
            else if (e_c > 0)
            {
                filtered_arr_bp = malloc(sizeof(int) * e_c);
                if (filtered_arr_bp == NULL)
                {
                    fclose(f_out);
                    func.del_arr(arr_bp);
#ifdef DYN_EXPORT
                    FreeLibrary(arr_lib);
                    FreeLibrary(file_io_lib);
#endif
                    return UNSUCCESSFUL_MEMORY_ALLOCATION;
                }
                filtered_arr_ep = filtered_arr_bp + e_c;
                e_c = func.key(arr_bp, arr_ep, &filtered_arr_bp, &filtered_arr_ep);
                if (e_c < 0)
                {
                    fclose(f_out);
                    func.del_arr(filtered_arr_bp);
                    func.del_arr(arr_bp);
#ifdef DYN_EXPORT
                    FreeLibrary(arr_lib);
                    FreeLibrary(file_io_lib);
#endif
                    return UNSUCCESSFUL_MEMORY_ALLOCATION;
                }
            }
            func.del_arr(arr_bp);
            func.mysort(filtered_arr_bp, (filtered_arr_ep - filtered_arr_bp), sizeof(int), func.compare_int);
            if (func.fprintf_arr(f_out, filtered_arr_bp, filtered_arr_ep))
            {
                fclose(f_out);
                func.del_arr(filtered_arr_ep);
#ifdef DYN_EXPORT
                FreeLibrary(arr_lib);
                FreeLibrary(file_io_lib);
#endif
                return WRITING_ERROR;
            }
            func.del_arr(filtered_arr_bp);
        }
        else
        {
            func.mysort(arr_bp, (arr_ep - arr_bp), sizeof(int), func.compare_int);
            if (func.fprintf_arr(f_out, arr_bp, arr_ep))
            {
                fclose(f_out);
                func.del_arr(arr_bp);
#ifdef DYN_EXPORT
                FreeLibrary(arr_lib);
                FreeLibrary(file_io_lib);
#endif
                return WRITING_ERROR;
            }
            func.del_arr(arr_bp);
        }
        fclose(f_out);
#ifdef DYN_EXPORT
        FreeLibrary(arr_lib);
        FreeLibrary(file_io_lib);
#endif
        return SUCCESS;
    }
    else
    {
#ifdef DYN_EXPORT
        FreeLibrary(arr_lib);
        FreeLibrary(file_io_lib);
#endif
        return INCORRECT_PARAMS;
    }
}