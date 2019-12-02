#include "singly_linked_lists.h"

/**
 * Delete nodes with duplicate values in a linked list.
 * O(n) time complexity.
 */
void remove_dups(node **head)
{
    node *slow, *fast;
    int slow_index, fast_index;

    slow = *head;
    slow_index = 0;
    while (slow)
    {
        fast = slow->next;
        fast_index = slow_index + 1;
        while (fast)
        {
            fast->n == slow->n
                ? delete_nodeint_at_index(head, fast_index)
                : fast_index++;
            fast = fast->next;
        }
        if (!slow->next)
            break;
        slow = slow->next;
        slow_index++;
    }
}

int main()
{
    node *head = NULL;
    int arr[] = {8, 1, 4, 1, 1, 4, 8, 8};
    int i, size = sizeof(arr) / sizeof(int);

    for (i = 0; i < size; i++)
        add_nodeint(&head, arr[i]);
    remove_dups(&head);
    print_list(head); // 8 -> 4 -> 1

    return 0;
}