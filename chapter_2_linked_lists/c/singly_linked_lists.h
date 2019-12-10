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
} sll_node;

size_t print_list(const sll_node *h);
size_t list_len(const sll_node *h);
sll_node *add_nodeint(sll_node **head, const int n);
int delete_nodeint_at_index(sll_node **head, unsigned int index);

#endif