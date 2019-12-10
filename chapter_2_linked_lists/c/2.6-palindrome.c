#include "singly_linked_lists.h"

/**
 * Determines if a linked list is a palindrome.
 * O(n) time and space complexity.
 */
int is_palindrome(sll_node **head)
{
    sll_node *slow = *head, *fast = *head, *prev = *head;
    sll_node *second = NULL, *mid = NULL;
    int res = 0;

    if (!fast || !fast->next)
        return (1);
    while (fast && fast->next)
    {
        fast = fast->next->next;
        prev = slow;
        slow = slow->next;
    }
    /* if odd, skip middle node */
    if (fast)
    {
        mid = slow;
        slow = slow->next;
    }
    second = slow;
    prev->next = NULL;
    reverse_linked_list(&second);
    res = compare_linked_list(*head, second);
    reverse_linked_list(&second);
    if (mid)
    {
        prev->next = mid;
        mid->next = second;
    }
    else
        prev->next = second;
    return (res);
}

int main()
{
    sll_node *head = NULL;
    int arr[] = {1, 2, 4, 8, 4, 2, 1};
    int i, size = sizeof(arr) / sizeof(int);

    for (i = 0; i < size; i++)
        add_nodeint(&head, arr[i]);
    printf("%i\n", is_palindrome(&head)); // 1

    sll_node *head2 = NULL;
    int arr2[] = {1, 2, 4, 4, 2, 1};
    size = sizeof(arr2) / sizeof(int);

    for (i = 0; i < size; i++)
        add_nodeint(&head2, arr2[i]);
    printf("%i\n", is_palindrome(&head2)); // 1

    sll_node *head3 = NULL;
    int arr3[] = {1, 2, 4, 8, 16, 4, 2, 1};
    size = sizeof(arr3) / sizeof(int);

    for (i = 0; i < size; i++)
        add_nodeint(&head3, arr3[i]);
    printf("%i\n", is_palindrome(&head3)); // 0

    return 0;
}