#include "polinom.h"

/**
 * @brief Calculates the value of polinom.
 * 
 * @param polinom 
 * @param point 
 * @return long long 
 */
long long polinom_value(const polinom_t polinom, const long long point)
{
    if (polinom.max_deg == 0)
        return polinom.degs->coefficient;
    long long result;
    node_t *ptr = polinom.degs;
    int multiplier = ptr->coefficient;
    int addendum = ptr->next->coefficient;

    for (int i = 0; i < polinom.max_deg; i++)
    {
        result = multiplier * point + addendum;
        multiplier = result;
        if (i != polinom.max_deg - 1)
        {
            ptr = ptr->next;
            addendum = ptr->next->coefficient;
        }
    }
    return result;
}

/**
 * @brief Calculates the derivative polinom.
 * 
 * @param polinom 
 * @return polinom_t 
 */
polinom_t derivative(const polinom_t polinom)
{
    if (polinom.max_deg == 0)
    {
        polinom_t derivative = { .degs = NULL, .max_deg = 0 };
        return derivative;
    }
    polinom_t derivative = { .max_deg = polinom.max_deg - 1, .degs = NULL };
    node_t *dhead;
    node_t *head = polinom.degs;
    for (int i = polinom.max_deg; i > 0; i--)
    {
        node_t *tmp = node_create(head->coefficient * i);
        if (tmp == NULL)
        {
            list_wipe(derivative.degs);
            return derivative;
        }

        if (derivative.degs == NULL)
        {
            derivative.degs = tmp;
            dhead = tmp;
        }
        else
        {
            dhead->next = tmp;
            dhead = tmp;
        }
        head = head->next;
    }
    return derivative;
}

/**
 * @brief Sums two polinoms.
 * 
 * @param polinom_1 
 * @param polinom_2 
 * @return polinom_t 
 */
polinom_t sum_polinoms(const polinom_t polinom_1, const polinom_t polinom_2)
{
    int curr_deg_1 = polinom_1.max_deg, curr_deg_2 = polinom_2.max_deg;
    polinom_t result = { .max_deg = (curr_deg_1 >= curr_deg_2) ? curr_deg_1 : curr_deg_2,
        .degs = NULL };
    node_t *rhead;
    node_t *head1 = polinom_1.degs;
    node_t *head2 = polinom_2.degs;
    while (curr_deg_1 >= 0)
    {
        node_t *tmp;
        if (curr_deg_1 > curr_deg_2)
            tmp = node_create(head1->coefficient);
        else if (curr_deg_2 > curr_deg_1)
            tmp = node_create(head2->coefficient);
        else
            tmp = node_create(head1->coefficient + head2->coefficient);
        if (tmp == NULL)
        {
            list_wipe(result.degs);
            return result;
        }
        if (curr_deg_1 > curr_deg_2)
            head1 = head1->next;
        else if (curr_deg_2 > curr_deg_1)
            head2 = head2->next;
        else
        {
            head1 = head1->next;
            head2 = head2->next;
        }
        if (result.degs == NULL)
        {
            result.degs = tmp;
            rhead = tmp;
        }
        else
        {
            rhead->next = tmp;
            rhead = tmp;
        }
        if (curr_deg_1 > curr_deg_2)
            curr_deg_1--;
        else if (curr_deg_2 > curr_deg_1)
            curr_deg_2--;
        else
        {
            curr_deg_1--;
            curr_deg_2--;
        }
    }
    return result;
}

/**
 * @brief Divides polinom in even and odd degrees.
 * 
 * @param polinom A source polinom.
 * @param even_degs A pointer to even degrees polinom.
 * @param odd_degs A pointer to odd degrees polinom.
 * @return int 
 */
int divide_polinom(const polinom_t polinom, polinom_t *even_degs, polinom_t *odd_degs)
{
    even_degs->degs = NULL;
    even_degs->max_deg = -1;
    odd_degs->degs = NULL;
    odd_degs->max_deg = -1;
    node_t *head = polinom.degs;
    node_t *e_head, *o_head;
    for (int i = polinom.max_deg; i >= 0; i--)
    {
        node_t *tmp = node_create(head->coefficient);
        if (tmp == NULL)
        {
            list_wipe(even_degs->degs);
            list_wipe(odd_degs->degs);
            return UNSUCCESSFUL_MEMORY_ALLOCATION;
        }
        if (i % 2 == 0)
        {
            if (even_degs->degs == NULL)
            {
                even_degs->degs = tmp;
                e_head = tmp;
            }
            else
            {
                e_head->next = tmp;
                e_head = tmp;
            }
            even_degs->max_deg++;
        }
        if (i % 2 == 1)
        {
            if (odd_degs->degs == NULL)
            {
                odd_degs->degs = tmp;
                o_head = tmp;
            }
            else
            {
                o_head->next = tmp;
                o_head = tmp;
            }
            odd_degs->max_deg++;
        }
        head = head->next;
    }
    // if (odd_degs->max_deg == -1)
    // {
    //     node_t *tmp = node_create(0);
    //     odd_degs->max_deg = 0;
    //     odd_degs->degs = tmp;
    //     if (tmp == NULL)
    //     {
    //         list_wipe(even_degs->degs);
    //         return UNSUCCESSFUL_MEMORY_ALLOCATION;
    //     }
    // }
    return SUCCESS;
}