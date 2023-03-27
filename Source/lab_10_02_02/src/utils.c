#include "utils.h"

#define READING_SUCCESS 0
#define READING_ERROR 1

/**
 * @brief Reads a string until the first occurence of the "new line" symbol
 *        and finishes it with a terminal null.
 * 
 * @param str_in Pointer to a string.
 * @param str_size Max string size.
 * @return int 
 */
int str_reading(char *str_in, const int str_size)
{
    int ch, i = 0;
    while ((ch = getchar()) != '\n' && ch != EOF && ch != '\0' && i < str_size)
    {
        str_in[i] = ch;
        i++;
    }
    if (((ch == '\n' || ch == EOF || ch == '\0') && i == 0) || i == str_size)
        return READING_ERROR;
    else
    {
        str_in[i] = '\0';
        return READING_SUCCESS;
    }
}