#include "singly_linked_lists.h"

/** 
 * Determines if a linked list is a palindrome
 * O(n) time and space complexity
 */
int is_palindrome(node **head)
{
    node *slow = *head, *fast = *head, *prev = *head;
    node *second = NULL, *mid = NULL;
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
    node *head = NULL;
    add_nodeint(&head, 1);
    add_nodeint(&head, 2);
    add_nodeint(&head, 4);
    add_nodeint(&head, 8);
    add_nodeint(&head, 4);
    add_nodeint(&head, 2);
    add_nodeint(&head, 1);
    printf("%i\n", is_palindrome(&head)); // 1

    node *head2 = NULL;
    add_nodeint(&head2, 1);
    add_nodeint(&head2, 2);
    add_nodeint(&head2, 4);
    add_nodeint(&head2, 4);
    add_nodeint(&head2, 2);
    add_nodeint(&head2, 1);
    printf("%i\n", is_palindrome(&head2)); // 1

    node *head3 = NULL;
    add_nodeint(&head3, 1);
    add_nodeint(&head3, 2);
    add_nodeint(&head3, 4);
    add_nodeint(&head3, 8);
    add_nodeint(&head3, 16);
    add_nodeint(&head3, 4);
    add_nodeint(&head3, 2);
    add_nodeint(&head3, 1);
    printf("%i\n", is_palindrome(&head3)); // 0
    return 0;
}