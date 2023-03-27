#ifndef __ARR_LIB_H__
#define __ARR_LIB_H__

#include <stdlib.h>

#ifdef EXPORT
#define DLL __declspec(dllexport)
#else
#define DLL __declspec(dllimport)
#endif

#define DECL __cdecl

#define SUCCESS 0
#define INCORRECT_INPUT 1

DLL int DECL calc_fib(int order);
DLL int DECL arr_fill_fib(int *arr, int size);
DLL int DECL del_duples(int *src, int src_size, int *dst, int dst_size);

#endif //__ARR_LIB_H__