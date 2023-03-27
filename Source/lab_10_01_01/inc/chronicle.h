#ifndef __CHRONICLE_H__
#define __CHRONICLE_H__

#define MAX_STR_LEN 100
#define MAX_NUMS 4
#define MAX_RECS 100

#include <stdio.h>
#include "list.h"

typedef struct
{
    char title[MAX_STR_LEN + 1];
    char year[MAX_NUMS + 1];
} event_t;

int read_chronicles(FILE *f, event_t database[]);

int read_line(FILE *file, char *s, int str_len);
int read_event(FILE *file, event_t *event);
int check_year(char *str);
int fread_chronicles(FILE *file, event_t db[], size_t *db_size);
void fprint_chronicles(FILE *f, node_t *head);
int form_list(event_t db[], size_t db_size, node_t **head);
int cmp_chronicles(const void *ptr1, const void *ptr2);

#endif