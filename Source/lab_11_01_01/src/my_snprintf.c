
#include "my_snprintf.h"

int my_snprintf(char *s, size_t n, char *format, ...)
{
    va_list arg_ptr;
    size_t str_curr_size = 0;

    va_start(arg_ptr, format);
    while (*format != '\0')
    {
        if (*format == '%')
        {
            format++;
            add_arg(&format, &s, &str_curr_size, n, &arg_ptr);
        }
        else
        {
            if (str_curr_size < n && s)
                s[str_curr_size] = *format;
            format++;
            str_curr_size++;
        }
    }

    va_end(arg_ptr);
    if (str_curr_size < n && s)
        s[str_curr_size] = '\0';
    else if (s)
        s[n - 1] = '\0';


    return str_curr_size;
}