#include "list.h"

node_t *node_create(int data)
{
    node_t *node = malloc(sizeof(node_t));
    if (node)
    {
        node->data = data;
        node->prev = NULL;
        node->next = NULL;
    }
    return node;
}

void node_free(node_t **node)
{
    if (!node || !*node)
        return;
    else
    {
        free(*node);
        *node = NULL;
    }
}

void list_push(node_t **head, node_t *elem)
{
    if (*head == NULL)
        *head = elem;
    else
    {
        (*head)->prev = elem;
        elem->next = *head;
        *head = elem;
    }
}

void list_wipe(node_t **head)
{
    while (*head)
    {
        if (*head == (*head)->next)
        {
            free(*head);
            return;
        }
        node_t *tmp = (*head)->next;
        free(*head);
        *head = tmp;
    }
}

void list_swap(node_t *l, node_t *r)
{
    int tmp = l->data;
    l->data = r->data;
    r->data = tmp;
}

#define FILTER_MOD 10
void list_bubble_sort(node_t *head)
{
    if (!list_len(head))
        return;
    int swapped;
    node_t *ptr1;
    node_t *lptr = NULL;
    if (head == NULL)
        return;
    do
    {
        swapped = 0;
        ptr1 = head;
        while (ptr1->next != lptr)
        {
            if (ptr1->data % FILTER_MOD > ptr1->next->data % FILTER_MOD)
            {
                list_swap(ptr1, ptr1->next);
                swapped = 1;
            }
            ptr1 = ptr1->next;
        }
        lptr = ptr1;
    } while (swapped);
}

#define MAX_LEN 10000
int list_len(node_t *head)
{
    int len = 0;
    while (head)
    {
        len++;
        if (len == MAX_LEN)
            return 0;
        head = head->next;
    }
    return len;
}

void list_print(node_t *head)
{
    if (list_len(head))
        while (head)
        {
            printf("%d ", head->data);
            head = head->next;
        }
}