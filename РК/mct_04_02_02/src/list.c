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

void list_insert_before(node_t **head, node_t *elem, node_t *before)
{
    if (before == NULL || head == NULL || elem == NULL)
        return;
    while (*head != NULL && *head != before)
        head = &(*head)->next;
    if (*head == NULL)
        return;
    elem->prev = before->prev;
    *head = elem;
    elem->next = before;
}

void list_am_insert(node_t **head)
{
    int size = list_len(*head);
    if (size == 0)
        return;
    int sum = list_sum(*head);
    int am = (int)floor((double)sum / size);
    node_t *am_node = node_create(am);
    if (!am_node)
        return;
    int curr_elem = 0;
    node_t *ptr = *head;
    while (curr_elem < size / 2)
    {
        ptr = ptr->next;
        curr_elem++;
    }
    list_insert_before(head, am_node, ptr);
}

int list_sum(node_t *head)
{
    size_t sum = 0;
    while (head)
    {
        sum += head->data;
        head = head->next;
    }
    return sum;
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