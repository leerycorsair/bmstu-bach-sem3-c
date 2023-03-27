#include "list.h"

int main(void)
{
    setbuf(stdout, NULL);
    int arr1[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15};
    size_t arr_size1 = 15;

    node_t *head = NULL;
    for (size_t i = 0; i < arr_size1; i++)
    {
        node_t *node = node_create(arr1[i]);
        if (!node)
        {
            list_wipe(&head);
            return EXIT_FAILURE;
        }
        list_push(&head, node);
    }
    printf("ТЕСТ1\n");
    list_print(head);
    list_am_insert(&head);
    printf("\n");
    list_print(head);
    list_wipe(&head);

    head = NULL;
    node_t *node = node_create(25);
    if (!node)
    {
        list_wipe(&head);
        return EXIT_FAILURE;
    }
    list_push(&head, node);
    head->next = head;
    head->prev = head;
    printf("\nТЕСТ2");
    list_print(head);
    list_am_insert(&head);
    printf("\n");
    list_print(head);
    list_wipe(&head);
    return EXIT_SUCCESS;
}