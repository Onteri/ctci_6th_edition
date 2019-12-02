#include "singly_linked_lists.h"

/**
 * Returns the kth element from last node.
 * O(n) time complexity.
 */
node *kth_to_last(node *head, int index)
{
    node *curr, *kth;

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
    int arr[] = {1, 2, 4, 8, 16, 32};
    int i, size = sizeof(arr) / sizeof(int);

    for (i = 0; i < size; i++)
        add_nodeint(&head, arr[i]);
    print_list(head); // 32 -> 16 -> 8 -> 4 -> 2 -> 1
    node *kth = kth_to_last(head, 2);
    printf("%i\n", kth->n); // 2

    return 0;
}
