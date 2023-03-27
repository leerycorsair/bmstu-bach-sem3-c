#include "list.h"

void list_wipe(node_t *head)
{
    node_t *next;
    for (; head; head = next)
    {
        next = head->next;
        node_del(&head);
    }
}

void node_del(node_t **node)
{
    if (node == NULL || *node == NULL)
        return;
    free((*node)->data);
    free(*node);
    *node = NULL;
}

node_t *node_create(void *data)
{
    node_t *tmp = malloc(sizeof(node_t));
    if (tmp == NULL)
        return NULL;
    tmp->data = data;
    tmp->next = NULL;
    return tmp;
}

void list_push_back(node_t **head, node_t *elem)
{
    if (head == NULL)
        return;
    if (*head == NULL)
        *head = elem;
    else
    {
        node_t *curr = *head;
        while (curr->next)
            curr = curr->next;
        curr->next = elem;
    }
}