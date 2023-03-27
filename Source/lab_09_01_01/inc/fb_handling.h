#ifndef FB_HANDLING_H
#define FB_HANDLING_H

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <ctype.h>

#define MAX_NUMS 4

typedef struct
{
    char *title;
    char *name;
    char *year;
} film_item;

void del_fb(film_item **fb, size_t size);
int read_sort_fb(FILE *file, film_item **fb, size_t *fb_size, char *field);
void print_fb(film_item *fb, size_t fb_size);
int find_film(film_item *fb, size_t fb_size, char *field, char *key);
int put_item(film_item record, film_item **fb, size_t *fb_size, char *field);
int check_year(char *str);

#endif