#include "singly_linked_lists.h"

/**
 * Deletes a node in the middle of a linked list.
 * O(n) time complexity.
 */
void delete_mid_node(sll_node *mid)
{
    sll_node *next;

    next = mid->next;
    mid->n = next->n;
    mid->next = next->next;
    free(next);
}

int main()
{
    sll_node *head = NULL;

    add_nodeint(&head, 1);
    add_nodeint(&head, 2);
    add_nodeint(&head, 4);
    sll_node *n8 = add_nodeint(&head, 8);
    add_nodeint(&head, 16);
    add_nodeint(&head, 32);
    print_list(head); // 32 -> 16 -> 8 -> 4 -> 2 -> 1
    delete_mid_node(n8);
    print_list(head); // 32 -> 16 -> 4 -> 2 -> 1

    return 0;
}