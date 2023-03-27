#include "memory_manager.h"

/**
 * @brief Wipes the list.
 * 
 * @param head Pointer to a head of a list.
 */
void list_wipe(node_t *head)
{
    node_t *next;
    for (; head; head = next)
    {
        next = head->next;
        del_node(head);
    }
}

/**
 * @brief Deletes a node of a list.
 * 
 * @param node Pointer to a node.
 */
void del_node(node_t *node)
{
    if (node != NULL)
        free(node);
    node = NULL;
}

/**
 * @brief Creates a node of a list.
 * 
 * @param value Data for writing in a node.
 * @return node_t* 
 */
node_t *node_create(int value)
{
    node_t *tmp = malloc(sizeof(node_t));
    if (tmp == NULL)
        return NULL;
    tmp->coefficient = value;
    tmp->next = NULL;
    return tmp;
}