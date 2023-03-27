#ifndef __POLINOM_H__
#define __POLINOM_H__

#include <stdio.h>
#include "err_codes.h"

typedef struct node_t node_t;

struct node_t
{
    int coefficient;
    node_t *next;
};

typedef struct
{
    int max_deg;
    node_t *degs;
} polinom_t;

long long polinom_value(const polinom_t polinom, const long long point);
polinom_t derivative(const polinom_t polinom);
polinom_t sum_polinoms(const polinom_t polinom_1, const polinom_t polinom_2);
int divide_polinom(const polinom_t polinom, polinom_t *even_degs, polinom_t *odd_degs);

#include "memory_manager.h"

#endif