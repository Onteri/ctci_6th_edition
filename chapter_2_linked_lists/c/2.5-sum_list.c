#include "singly_linked_lists.h"

/**
 * Adds the values of two linked lists by creating a new list.
 * O(a + b) solution, with a and b being lengths of respective lists.
 */
sll_node *sum_list(sll_node *list1, sll_node *list2, int carry)
{
    int value;
    sll_node *new_node, *next_node;

    if (!list1 && !list2 && !carry)
        return NULL;
    value = carry;
    if (list1)
        value += list1->n;
    if (list2)
        value += list2->n;
    new_node = malloc(sizeof(sll_node));
    new_node->n = value % 10;
    if (list1 || list2)
    {
        /* recursive call */
        next_node = sum_list(
            list1 ? list1->next : NULL,
            list2 ? list2->next : NULL,
            value >= 10 ? 1 : 0);
        new_node->next = next_node;
    }
    return new_node;
}

int main()
{
    sll_node *head = NULL;
    add_nodeint(&head, 9);
    add_nodeint(&head, 9);
    add_nodeint(&head, 9);

    sll_node *head2 = NULL;
    add_nodeint(&head2, 1);

    print_list(head);  // 9 -> 9 -> 9
    print_list(head2); // 1

    sll_node *head3 = sum_list(head, head2, 0);
    print_list(head3); // 0 -> 0 -> 0 -> 1

    return 0;
}