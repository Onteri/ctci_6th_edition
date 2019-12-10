#ifndef SINGLY_LINKED_LISTS
#define SINGLY_LINKED_LISTS

#include <stdio.h>
#include <stdlib.h>

/**
 * Singly linked list node.
 */
typedef struct sll_node
{
    int n;
    struct sll_node *next;
} node;

#endif