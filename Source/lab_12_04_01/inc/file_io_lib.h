#ifndef __FILE_IO_LIB_H__
#define __FILE_IO_LIB_H__

#include "err_codes.h"
#include <stdio.h>

#ifdef STATIC
int fget_arr_size(FILE *f, size_t *size);
int fread_arr(FILE *f, int *arr_bp, int **arr_ep);
int fprintf_arr(FILE *f, int *arr_bp, int *arr_ep);
#endif

#ifdef DYN_EXPORT
int fget_arr_size(FILE *f, size_t *size);
int fread_arr(FILE *f, int *arr_bp, int **arr_ep);
int fprintf_arr(FILE *f, int *arr_bp, int *arr_ep);
#endif

#ifdef EXPORT
#define DLL __declspec(dllexport)
#define DECL __cdecl
DLL int DECL fget_arr_size(FILE *f, size_t *size);
DLL int DECL fread_arr(FILE *f, int *arr_bp, int **arr_ep);
DLL int DECL fprintf_arr(FILE *f, int *arr_bp, int *arr_ep);
#endif

#ifdef IMPORT
#define DLL __declspec(dllimport)
#define DECL __cdecl
DLL int DECL fget_arr_size(FILE *f, size_t *size);
DLL int DECL fread_arr(FILE *f, int *arr_bp, int **arr_ep);
DLL int DECL fprintf_arr(FILE *f, int *arr_bp, int *arr_ep);
#endif

#endif