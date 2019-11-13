#include "singly_linked_lists.h"

/** 
 * Returns the kth element from last node
 * O(n) time complexity
 */
node *kth_to_last(node *head, int index)
{
    node *curr;
    node *kth;

    curr = kth = head;
    while (index)
    {
        curr = curr->next;
        index--;
    }
    while (curr)
    {
        curr = curr->next;
        kth = kth->next;
    }
    return kth;
}

int main()
{
    node *head = NULL;
    add_nodeint(&head, 1);
    add_nodeint(&head, 2);
    add_nodeint(&head, 4);
    add_nodeint(&head, 8);
    add_nodeint(&head, 16);
    add_nodeint(&head, 32);
    print_list(head); // 32 -> 16 -> 8 -> 4 -> 2 -> 1
    node *kth = kth_to_last(head, 2);
    printf("%i\n", kth->n); // 2
    return 0;
}
