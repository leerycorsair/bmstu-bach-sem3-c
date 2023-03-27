#ifndef __LIST_H__
#define __LIST_H__

#include <stdlib.h>
#include <stdio.h>

typedef struct node_t node_t;
struct node_t
{
    int data;
    node_t *prev;
    node_t *next;
};

node_t *node_create(int data);

void node_free(node_t **node);
void list_push(node_t **head, node_t *elem);
void list_wipe(node_t **head);
void list_swap(node_t *l, node_t *r);
void list_bubble_sort(node_t *head);
void list_print(node_t *head);

int list_len(node_t *head);

#endif // __LIST_H__