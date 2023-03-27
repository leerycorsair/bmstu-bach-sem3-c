#ifndef __MY_SNPRINTF_H__
#define __MY_SNPRINTF_H__

#include <stdlib.h>
#include <stdarg.h>

#include "str_tools.h"

int my_snprintf(char *s, size_t n, char *format, ...);

#endif