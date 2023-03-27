#include "list.h"

int main(void)
{
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
    list_bubble_sort(head);
    printf("\n");
    list_print(head);
    list_wipe(&head);

    int arr2[] = {15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    size_t arr_size2 = 15;

    head = NULL;
    for (size_t i = 0; i < arr_size2; i++)
    {
        node_t *node = node_create(arr2[i]);
        if (!node)
        {
            list_wipe(&head);
            return EXIT_FAILURE;
        }
        list_push(&head, node);
    }
    printf("\n");
    printf("ТЕСТ2\n");
    list_print(head);
    list_bubble_sort(head);
    printf("\n");
    list_print(head);
    list_wipe(&head);

    int arr3[] = {1};
    size_t arr_size3 = 1;

    head = NULL;
    for (size_t i = 0; i < arr_size3; i++)
    {
        node_t *node = node_create(arr3[i]);
        if (!node)
        {
            list_wipe(&head);
            return EXIT_FAILURE;
        }
        list_push(&head, node);
    }
    printf("\n");
    printf("ТЕСТ3\n");
    list_print(head);
    list_bubble_sort(head);
    printf("\n");
    list_print(head);
    list_wipe(&head);

    printf("\nТЕСТ4\n");
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
    list_print(head);
    list_bubble_sort(head);
    printf("\n");
    list_print(head);
    list_wipe(&head);
    

    return EXIT_SUCCESS;
}