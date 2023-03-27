#ifndef __LIST_H__
#define __LIST_H__

#include <stdlib.h>

#include "err_codes.h"

typedef struct node_t node_t;

struct node_t
{
    void *data;
    node_t *next;
};

#include "memory_manager.h"

node_t *find(node_t *head, const void *data, int (*comparator)(const void *, const void *));
void *pop_front(node_t **head);
void *pop_back(node_t **head);
void insert(node_t **head, node_t *elem, node_t *before);
int copy(node_t *head, node_t **new_head);
void append(node_t **head_a, node_t **head_b);
void remove_duplicates(node_t **head, int (*comparator)(const void *, const void *));
void reverse(node_t **head);
void sorted_insert(node_t **head, node_t *element, int (*comparator)(const void *, const void *));
node_t *sort(node_t *head, int (*comparator)(const void *, const void *));
#endif