#include "str_tools.h"

#define MAX_NUM_LEN 32

void add_arg(char **format, char **s, size_t *str_curr_size, size_t max_size, va_list *arg_ptr)
{
    if (**format == 'd' || **format == 'i')
    {
        int son_base = 10;
        char tmp_str[MAX_NUM_LEN + 1];
        long_to_str(tmp_str, va_arg(*arg_ptr, int), son_base);
        add_str(*s, str_curr_size, max_size, tmp_str);
        (*format)++;
    }
    else if (**format == 'o')
    {
        unsigned son_base = 8;
        char tmp_str[MAX_NUM_LEN + 1];
        unsigned_long_to_str(tmp_str, va_arg(*arg_ptr, unsigned), son_base);
        add_str(*s, str_curr_size, max_size, tmp_str);
        (*format)++;
    }
    else if (**format == 'l' && (*(*format + 1) == 'i' || *(*format + 1) == 'd'))
    {
        int son_base = 10;
        char tmp_str[MAX_NUM_LEN + 1];
        long_to_str(tmp_str, va_arg(*arg_ptr, long), son_base);
        add_str(*s, str_curr_size, max_size, tmp_str);
        (*format)++;
        (*format)++;
    }
    else if (**format == 'l' && *(*format + 1) == 'o')
    {
        unsigned son_base = 8;
        char tmp_str[MAX_NUM_LEN + 1];
        unsigned_long_to_str(tmp_str, va_arg(*arg_ptr, unsigned long), son_base);
        add_str(*s, str_curr_size, max_size, tmp_str);
        (*format)++;
        (*format)++;
    }
    else if (**format == 's')
    {
        char *tmp_str = va_arg(*arg_ptr, char *);
        add_str(*s, str_curr_size, max_size, tmp_str);
        (*format)++;
    }
    else if (**format == 'c')
    {
        char tmp_char = va_arg(*arg_ptr, int);
        if (*str_curr_size < max_size && *s)
            *(*s + (*str_curr_size)) = tmp_char;
        (*str_curr_size)++;
        (*format)++;
    }
    else if (**format == 'h' && (*(*format + 1) == 'i' || *(*format + 1) == 'd'))
    {
        int son_base = 10;
        char tmp_str[MAX_NUM_LEN + 1];
        short_to_str(tmp_str, va_arg(*arg_ptr, long), son_base);
        add_str(*s, str_curr_size, max_size, tmp_str);
        (*format)++;
        (*format)++;
    }
    else if (**format == 'h' && *(*format + 1) == 'o')
    {
        unsigned son_base = 8;
        char tmp_str[MAX_NUM_LEN + 1];
        unsigned_long_to_str(tmp_str, va_arg(*arg_ptr, unsigned long), son_base);
        add_str(*s, str_curr_size, max_size, tmp_str);
        (*format)++;
        (*format)++;
    }
    else if (**format == 'h' && *(*format + 1) == 'x')
    {
        unsigned son_base = 16;
        char tmp_str[MAX_NUM_LEN + 1];
        unsigned_long_to_str(tmp_str, va_arg(*arg_ptr, unsigned long), son_base);
        add_str(*s, str_curr_size, max_size, tmp_str);
        (*format)++;
        (*format)++;
    }
    else if (**format == 'l' && *(*format + 1) == 'x')
    {
        unsigned son_base = 16;
        char tmp_str[MAX_NUM_LEN + 1];
        unsigned_long_to_str(tmp_str, va_arg(*arg_ptr, unsigned long), son_base);
        add_str(*s, str_curr_size, max_size, tmp_str);
        (*format)++;
        (*format)++;
    }
    else if (**format == 'x')
    {
        unsigned son_base = 16;
        char tmp_str[MAX_NUM_LEN + 1];
        unsigned_long_to_str(tmp_str, va_arg(*arg_ptr, unsigned long), son_base);
        add_str(*s, str_curr_size, max_size, tmp_str);
        (*format)++;
    }
}

void str_reverse(char *str, size_t str_len)
{
    for (int i = 0; i < str_len / 2; i++)
    {
        char tmp = *(str + i);
        *(str + i) = *(str + str_len - i - 1);
        *(str + str_len - i - 1) = tmp;
    }
}

void long_to_str(char *str, long num, int base)
{
    unsigned long cur_num;
    size_t curr_len = 0, neg_check;
    if (num < 0)
    {
        neg_check = 1;
        cur_num = -num;
    }
    else
    {
        neg_check = 0;
        cur_num = num;
    }

    do
    {
        str[curr_len] = (cur_num % base) + '0';
        curr_len++;
        cur_num /= base;
    } while (cur_num);

    if (neg_check)
    {
        str[curr_len] = '-';
        curr_len++;
    }
    str[curr_len] = '\0';
    str_reverse(str, curr_len);
}

void short_to_str(char *str, short num, int base)
{
    unsigned short cur_num;
    size_t curr_len = 0, neg_check;
    if (num < 0)
    {
        neg_check = 1;
        cur_num = -num;
    }
    else
    {
        neg_check = 0;
        cur_num = num;
    }

    do
    {
        str[curr_len] = (cur_num % base) + '0';
        curr_len++;
        cur_num /= base;
    } while (cur_num);

    if (neg_check)
    {
        str[curr_len] = '-';
        curr_len++;
    }
    str[curr_len] = '\0';
    str_reverse(str, curr_len);
}

void unsigned_long_to_str(char *str, unsigned long num, unsigned base)
{
    char nums[16] = "0123456789abcdef";
    size_t curr_len = 0;
    do
    {
        str[curr_len] = nums[(num % base)];
        curr_len++;
        num /= base;
    } while (num);
    str[curr_len] = '\0';
    str_reverse(str, curr_len);
}

void add_str(char *str, size_t *str_curr_size, size_t max_size, char *tmp_str)
{
    while (*tmp_str)
    {
        if (*str_curr_size < max_size)
            str[*str_curr_size] = *tmp_str;
        tmp_str++;
        (*str_curr_size)++;
    }
}
