#ifndef __LIST_H__
#define __LIST_H__

#include <stdlib.h>

typedef struct node_t node_t;
struct node_t
{
    void *data;
    node_t *next;
};

node_t *node_create(void *data);
void node_del(node_t **node);

void list_wipe(node_t *head);
void list_push_back(node_t **head, node_t *elem);

#endif // __LIST_H__