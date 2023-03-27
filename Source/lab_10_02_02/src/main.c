#define __USE_MINGW_ANSI_STDIO

#include "err_codes.h"
#include "utils.h"
#include "polinom.h"
#include "polinom_io.h"
#include "memory_manager.h"

#include <string.h>

#define MAX_MENU_OPTION_LEN 3

int main(void)
{
    setbuf(stdout, NULL);
    char menu_option[MAX_MENU_OPTION_LEN + 1];
    if (str_reading(menu_option, MAX_MENU_OPTION_LEN + 1) || (strcmp(menu_option, "val") && strcmp(menu_option, "ddx") && strcmp(menu_option, "sum") && strcmp(menu_option, "dvd")))
        return INCORRECT_MENU_OPTION;

    polinom_t polinom = { .max_deg = -1, .degs = NULL };
    if (read_polinom(&polinom))
        return READING_ERROR;

    if (!strcmp(menu_option, "val"))
    {
        long long point;
        if (!scanf("%lld", &point))
        {
            list_wipe(polinom.degs);
            return READING_ERROR;
        }
        long long result;
        result = polinom_value(polinom, point);
        printf("%lld", result);
    }
    else if (!strcmp(menu_option, "ddx"))
    {
        polinom_t derivative_polinom;
        derivative_polinom = derivative(polinom);
        if (derivative_polinom.degs == NULL && derivative_polinom.max_deg != 0)
        {
            list_wipe(polinom.degs);
            return UNSUCCESSFUL_MEMORY_ALLOCATION;
        }
        print_polinom(derivative_polinom);
        list_wipe(derivative_polinom.degs);
    }
    else if (!strcmp(menu_option, "sum"))
    {
        polinom_t extra_polinom = { .max_deg = -1, .degs = NULL };
        if (read_polinom(&extra_polinom))
        {
            list_wipe(polinom.degs);
            return READING_ERROR;
        }
        polinom_t summary;
        summary = sum_polinoms(polinom, extra_polinom);
        if (summary.degs == NULL)
        {
            list_wipe(polinom.degs);
            list_wipe(extra_polinom.degs);
            return UNSUCCESSFUL_MEMORY_ALLOCATION;
        }
        print_polinom(summary);
        list_wipe(summary.degs);
        list_wipe(extra_polinom.degs);
    }
    else if (!strcmp(menu_option, "dvd"))
    {
        polinom_t even_degs;
        polinom_t odd_degs;
        if (divide_polinom(polinom, &even_degs, &odd_degs))
        {
            list_wipe(polinom.degs);
            return UNSUCCESSFUL_MEMORY_ALLOCATION;
        }
        print_polinom(odd_degs);
        printf("\n");
        print_polinom(even_degs);
        list_wipe(odd_degs.degs);
        list_wipe(even_degs.degs);
    }
    list_wipe(polinom.degs);
    return SUCCESS;
}