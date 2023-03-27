#include "polinom_io.h"
#include "err_codes.h"

/**
 * @brief Reads a polinom from STDIN.
 * 
 * @param polinom Pointer to a polinom.
 * @return int 
 */
int read_polinom(polinom_t *polinom)
{
    if (!scanf("%d", &polinom->max_deg) || polinom->max_deg <= 0)
        return READING_ERROR;
    
    polinom->max_deg -= 1;

    node_t *ptr;
    for (int i = 0; i <= polinom->max_deg; i++)
    {
        int value;
        if (!scanf("%d", &value))
        {
            list_wipe(polinom->degs);
            return READING_ERROR;
        }
        node_t *node = node_create(value);
        if (node == NULL)
        {
            list_wipe(polinom->degs);
            return UNSUCCESSFUL_MEMORY_ALLOCATION;
        }
        if (polinom->degs == NULL)
        {
            polinom->degs = node;
            ptr = node;
        }
        else
        {
            ptr->next = node;
            ptr = node;
        }
    }
    return SUCCESS;
}

/**
 * @brief Prints polinom coefficients in STDOUT.
 * 
 * @param polinom 
 */
void print_polinom(const polinom_t polinom)
{
    node_t *head = polinom.degs;
    for (; head; head = head->next)
        printf("%d ", head->coefficient);
    printf("L");
}