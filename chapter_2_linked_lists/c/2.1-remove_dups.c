#include "singly_linked_lists.h"

/** 
 * Delete nodes with duplicate values in a linked list
 * O(n**2) time complexity 
 */
void remove_dups(node **head)
{
    node *slow;
    node *fast;
    int slow_index;
    int fast_index;

    slow = *head;
    slow_index = 0;
    while (slow->next)
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
    add_nodeint(&head, 8);
    add_nodeint(&head, 1);
    add_nodeint(&head, 4);
    add_nodeint(&head, 1);
    add_nodeint(&head, 1);
    add_nodeint(&head, 4);
    add_nodeint(&head, 8);
    add_nodeint(&head, 8);
    remove_dups(&head);
    print_list(head); // 8 -> 4 -> 1
    return 0;
}