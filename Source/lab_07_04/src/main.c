
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../inc/err_codes.h"
#include "../inc/file_io.h"
#include "../inc/arr_handling.h"

int main(int argc, char **argv)
{
    setbuf(stdout, NULL);

    if (argc == 3 || (argc == 4 && strcmp(argv[3], "f") == 0))
    {
        FILE *f_in = fopen(argv[1], "r");
        if (f_in == NULL)
            return NO_IN_FILE;

        size_t arr_size = 0;
        if (fget_arr_size(f_in, &arr_size) || arr_size == 0)
        {
            fclose(f_in);
            return INCORRECT_FILE_CONTENT;
        }

        fclose(f_in);
        int *arr_bp = NULL, *arr_ep = NULL;
        if ((arr_bp = arr_allocation(arr_size)) == NULL)
            return UNSUCCESSFUL_MEMORY_ALLOCATION;

        f_in = fopen(argv[1], "r");
        fread_arr(f_in, arr_bp, &arr_ep);
        fclose(f_in);

        FILE *f_out = fopen(argv[2], "w");
        if (f_out == NULL)
        {
            del_arr(arr_bp);
            return OUT_FILE_ERROR;
        }
        if (argc == 4)
        {
            int *filtered_arr_bp = NULL, *filtered_arr_ep = NULL;
            if (key(arr_bp, arr_ep, &filtered_arr_bp, &filtered_arr_ep))
            {
                fclose(f_out);
                del_arr(arr_bp);
                return FILTER_ERROR;
            }
            del_arr(arr_bp);
            mysort(filtered_arr_bp, (filtered_arr_ep - filtered_arr_bp), sizeof(int), &compare_int);
            if (fprintf_arr(f_out, filtered_arr_bp, filtered_arr_ep))
            {
                fclose(f_out);
                del_arr(filtered_arr_ep);
                return WRITING_ERROR;
            }
            del_arr(filtered_arr_bp);
        }
        else
        {
            mysort(arr_bp, (arr_ep - arr_bp), sizeof(int), &compare_int);
            if (fprintf_arr(f_out, arr_bp, arr_ep))
            {
                fclose(f_out);
                del_arr(arr_bp);
                return WRITING_ERROR;
            }
            del_arr(arr_bp);
        }
        fclose(f_out);
        return SUCCESS;
    }
    else
        return INCORRECT_PARAMS;
}