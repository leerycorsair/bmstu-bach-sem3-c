#ifndef __ARR_LIB_H__
#define __ARR_LIB_H__

#include <stdlib.h>
#include <stdio.h>
#include "err_codes.h"

#ifdef STATIC
void *arr_allocation(size_t arr_size);
void del_arr(int *arr);
void mysort(void *base, size_t nmemb, size_t size, int (*compar)(const void *, const void *));
void swap(void *a, void *b, size_t size);
int key(const int *pb_src, const int *pe_src, int **pb_dst, int **pe_dst);
int compare_int(const void *p, const void *q);
#endif

#ifdef DYN_EXPORT
void *arr_allocation(size_t arr_size);
void del_arr(int *arr);
void mysort(void *base, size_t nmemb, size_t size, int (*compar)(const void *, const void *));
void swap(void *a, void *b, size_t size);
int key(const int *pb_src, const int *pe_src, int **pb_dst, int **pe_dst);
int compare_int(const void *p, const void *q);
#endif

#ifdef EXPORT
#define DLL __declspec(dllexport)
#define DECL __cdecl
DLL void *DECL arr_allocation(size_t arr_size);
DLL void DECL del_arr(int *arr);
DLL void DECL mysort(void *base, size_t nmemb, size_t size, int (*compar)(const void *, const void *));
DLL void DECL swap(void *a, void *b, size_t size);
DLL int DECL key(const int *pb_src, const int *pe_src, int **pb_dst, int **pe_dst);
DLL int DECL compare_int(const void *p, const void *q);
#endif

#ifdef IMPORT
#define DLL __declspec(dllimport)
#define DECL __cdecl
DLL void *DECL arr_allocation(size_t arr_size);
DLL void DECL del_arr(int *arr);
DLL void DECL mysort(void *base, size_t nmemb, size_t size, int (*compar)(const void *, const void *));
DLL void DECL swap(void *a, void *b, size_t size);
DLL int DECL key(const int *pb_src, const int *pe_src, int **pb_dst, int **pe_dst);
DLL int DECL compare_int(const void *p, const void *q);
#endif

#endif