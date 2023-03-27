#ifndef FB_HANDLING_H
#define FB_HANDLING_H

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <ctype.h>

#define MAX_RECS 15
#define MAX_STR_LEN 25
#define MAX_NUMS 4

typedef struct
{
    char title[MAX_STR_LEN + 1];
    char name[MAX_STR_LEN + 1];
    char year[MAX_NUMS + 1];
} film_item;

int read_sort_fb(FILE *file, film_item fb[], size_t *fb_size, char *field);
void print_fb(film_item fb[], size_t fb_size);
int find_film(film_item fb[], size_t fb_size, char *field, char *key);
void put_item(film_item record, film_item fb[], size_t *fb_size, char *field);
int check_year(char *str);

#endif