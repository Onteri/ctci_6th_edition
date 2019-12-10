#include "singly_linked_lists.h"

/**
 * Determines if linked list is circular.
 * O(n) solution.
 */
int is_circular(sll_node *head)
{
    sll_node *hare, *tortoise;

    hare = tortoise = head;
    while (hare && hare->next)
    {
        hare = hare->next->next;
        tortoise = tortoise->next;
        if (hare == tortoise)
            return 1;
    }
    return 0;
}

int main()
{
    sll_node *head = NULL;
    add_nodeint(&head, 1);
    add_nodeint(&head, 2);
    sll_node *n4 = add_nodeint(&head, 4);
    add_nodeint(&head, 8);
    add_nodeint(&head, 16);
    sll_node *n32 = add_nodeint(&head, 32);
    printf("%i\n", is_circular(head)); // 0
    n4->next = n32;
    printf("%i\n", is_circular(head)); // 1

    return 0;
}