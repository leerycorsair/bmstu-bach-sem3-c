#ifndef __STR_TOOLS_H__
#define __STR_TOOLS_H__

#include <stdarg.h>
#include <stdlib.h>

void add_arg(char **format, char **s, size_t *str_curr_size, size_t max_size, va_list *arg_ptr);
void str_reverse(char *str, size_t str_len);
void long_to_str(char *str, long num, int base);
void short_to_str(char *str, short num, int base);
void unsigned_long_to_str(char *str, unsigned long num, unsigned base);
void add_str(char *str, size_t *str_curr_size, size_t max_size, char *tmp_str);

#endif