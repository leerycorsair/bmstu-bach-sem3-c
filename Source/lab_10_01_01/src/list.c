#include "list.h"

/**
 * @brief Finds the first occurrence of data in a list.
 *        If nothing is found, returns a pointer to data.
 *        Otherwise returns a pointer to a node of a list.
 * 
 * @param head A pointer to a head of a list.
 * @param data A pointer to data.
 * @param comparator A pointer to a comporator function.
 * @return node_t* A pointer to a node of a list with data.
 */
node_t *find(node_t *head, const void *data, int (*comparator)(const void *, const void *))
{
    if (head == NULL || data == NULL)
        return NULL;
    for (; head; head = head->next)
        if (!comparator(data, head->data))
            return head;
    return NULL;
}

/**
 * @brief Pops the first element from a list and returns the pointer to data in it.
 * 
 * @param head A pointer to a pointer to a head of a list.
 * @return void* A pointer to data.
 */
void *pop_front(node_t **head)
{
    if (head == NULL || (*head) == NULL)
        return NULL;
    else
    {
        void *ptr = (*head)->data;
        node_t *next = (*head)->next;
        del_node(*head);
        *head = next;
        return ptr;
    }
}

/**
 * @brief Pops the last element from a list and returns the pointer to data in it.
 * 
 * @param head A pointer to a pointer to a head of a list.
 * @return void* A pointer to data.
 */
void *pop_back(node_t **head)
{
    if (head == NULL)
        return NULL;
    while (*head != NULL && (*head)->next != NULL)
        head = &(*head)->next;
    if (*head == NULL)
        return NULL;
    void *data = (*head)->data;
    free(*head);
    *head = NULL;
    return data;
}

/**
 * @brief Inserts a node before a element of a list.
 * 
 * @param head A pointer to a pointer to a head of a list.
 * @param elem A pointer to a node to insert.
 * @param before A pointer to a node, which must be after an element, when the insertion is completed.
 */
void insert(node_t **head, node_t *elem, node_t *before)
{
    if (before == NULL || head == NULL || elem == NULL)
        return;
    while (*head != NULL && *head != before)
        head = &(*head)->next;
    if (*head == NULL)
        return;
    *head = elem;
    elem->next = before;
}

/**
 * @brief Creates a copy of a list.
 * 
 * @param head A pointer to a source list.
 * @param new_head A pointer to a pointer to a head of a destination list.
 * @return int Error code.
 */
int copy(node_t *head, node_t **new_head)
{
    if (head == NULL || new_head == NULL || *new_head != NULL)
        return INCORRECT_PARAMS;
    node_t *ptr;
    for (; head; head = head->next)
    {
        node_t *node = node_create(head->data);
        if (node == NULL)
        {
            list_wipe(*new_head);
            return UNSUCCESSFUL_MEMORY_ALLOCATION;
        }
        if (*new_head == NULL)
        {
            *new_head = node;
            ptr = node;
        }
        else
        {
            ptr->next = node;
            ptr = ptr->next;
        }
    }
    return SUCCESS;
}

/**
 * @brief Appends the second list in the first one.
 * 
 * @param head_a A pointer to a pointer to a head of the first list.
 * @param head_b A pointer to a pointer to a head of the second list.
 */
void append(node_t **head_a, node_t **head_b)
{
    while (*head_a != NULL)
        head_a = &(*head_a)->next;

    *head_a = *head_b;
    *head_b = NULL;
}

/**
 * @brief Gets a sorted list and deletes duplicates.
 * 
 * @param head A pointer to a pointer to a head of a list.
 * @param comparator A pointer to a comporator function. 
 */
void remove_duplicates(node_t **head, int (*comparator)(const void *, const void *))
{
    if ((head == NULL) || (*head == NULL))
        return;
    node_t *ptr = (*head)->next;
    node_t *previous = (*head);
    while (ptr)
        if (!comparator(previous->data, ptr->data))
        {
            previous->next = ptr->next;
            node_t *tmp = ptr->next;
            del_node(ptr);
            ptr = tmp;
        }
        else
        {
            previous = ptr;
            ptr = ptr->next;
        }
}

// /**
//  * @brief Reverses the list.
//  * 
//  * @param head A pointer to a pointer to a head of a list.
//  */
// void reverse(node_t **head)
// {
//     if (head == NULL || *head == NULL)
//         return;
//     node_t *rest = (*head)->next;
//     (*head)->next = NULL;
//     node_t *elem;
//     while (rest)
//     {
//         elem = rest;
//         rest = rest->next;
//         elem->next = *head;
//         *head = elem;
//     }
// }

/**
 * @brief Inserts a node in a list without the order disruption.
 * 
 * @param head A pointer to a pointer to a head of a list.
 * @param element A pointer to a node to insert.
 * @param comparator A pointer to a comporator function. 
 */
void sorted_insert(node_t **head, node_t *element, int (*comparator)(const void *, const void *))
{
    if (head == NULL || element == NULL)
        return;

    while (*head != NULL && comparator(element->data, (*head)->data) >= 0)
        head = &(*head)->next;

    element->next = *head;
    *head = element;
}

/**
 * @brief Sorts a list.
 * 
 * @param head A pointer to a head of a list.
 * @param comparator A pointer to a comporator function.
 */
node_t *sort(node_t *head, int (*comparator)(const void *, const void *))
{
    if (head == NULL)
        return NULL;

    node_t *result = NULL;
    node_t *tmp_ptr;

    while (head != NULL)
    {
        tmp_ptr = head->next;
        sorted_insert(&result, head, comparator);
        head = tmp_ptr;
    }
    return result;
}