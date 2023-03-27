#define __USE_MINGW_ANSI_STDIO

#include "err_codes.h"
#include "utils.h"
#include "list.h"
#include "matrix.h"

#include <string.h>

#define MAX_MENU_OPTION_LEN 3

int main(void)
{
    setbuf(stdout, NULL);
    char menu_option[MAX_MENU_OPTION_LEN + 1];
    if (str_reading(menu_option, MAX_MENU_OPTION_LEN + 1) || (strcmp(menu_option, "out") && strcmp(menu_option, "add") && strcmp(menu_option, "mul") && strcmp(menu_option, "lin")))
        return INCORRECT_MENU_OPTION;

    if (!strcmp(menu_option, "out"))
    {
        node_t *matrix1 = NULL;
        if (matrix_read(&matrix1))
        {
            list_wipe(matrix1);
            return READING_ERROR;
        }
        matrix_print(matrix1);
        list_wipe(matrix1);
    }
    else if (!strcmp(menu_option, "add"))
    {
        node_t *matrix1 = NULL;
        if (matrix_read(&matrix1))
        {
            list_wipe(matrix1);
            return READING_ERROR;
        }
        node_t *matrix2 = NULL;
        if (matrix_read(&matrix2))
        {
            list_wipe(matrix1);
            list_wipe(matrix2);
            return READING_ERROR;
        }
        node_t *matrix_res = NULL;
        if (matrix_addition(matrix1, matrix2, &matrix_res))
        {
            list_wipe(matrix1);
            list_wipe(matrix2);
            list_wipe(matrix_res);
            return UNSUCCESSFUL_MEMORY_ALLOCATION;
        }
        matrix_print(matrix_res);
        list_wipe(matrix1);
        list_wipe(matrix2);
        list_wipe(matrix_res);
    }
    else if (!strcmp(menu_option, "mul"))
    {
        node_t *matrix1 = NULL;
        if (matrix_read(&matrix1))
        {
            list_wipe(matrix1);
            return READING_ERROR;
        }
        node_t *matrix2 = NULL;
        if (matrix_read(&matrix2))
        {
            list_wipe(matrix1);
            list_wipe(matrix2);
            return READING_ERROR;
        }
        node_t *matrix_res = NULL;
        if (matrix_multiplication(matrix1, matrix2, &matrix_res))
        {
            list_wipe(matrix1);
            list_wipe(matrix2);
            list_wipe(matrix_res);
            return UNSUCCESSFUL_MEMORY_ALLOCATION;
        }
        matrix_print(matrix_res);
        list_wipe(matrix1);
        list_wipe(matrix2);
        list_wipe(matrix_res);
    }
    else if (!strcmp(menu_option, "lin"))
    {
        node_t *matrix1 = NULL;
        if (matrix_read(&matrix1))
        {
            list_wipe(matrix1);
            return READING_ERROR;
        }
        matrix_del_max_row(&matrix1);
        matrix_print(matrix1);
        list_wipe(matrix1);
    }
    return SUCCESS;
}