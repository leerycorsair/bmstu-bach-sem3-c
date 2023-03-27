#ifndef __LIST_H__
#define __LIST_H__

#include <stdlib.h>
#include <stdio.h>
#include <math.h>

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
void list_print(node_t *head);
void list_insert_before(node_t **head, node_t *elem, node_t *before);
void list_am_insert(node_t **head);
int list_len(node_t *head);
int list_sum(node_t *head);

#endif // __LIST_H__