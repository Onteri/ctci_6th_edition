#include "singly_linked_lists.h"

/* Partitions a linked list according to a number
 * All values lower than number will go on the left and 
 * all values higher and equal will go on the right
 * This solution is unstable, but performs at
 * O(n) time complexity */
void partition(node **head, int partition)
{
    node *start, *end, *curr, *next;

    start = end = curr = *head;
    while (curr)
    {
        next = curr->next;
        if (curr->n < partition)
        {
            curr->next = start;
            start = curr;
        }
        else
        {
            end->next = curr;
            end = curr;
        }
        curr = next;
    }
    end->next = NULL;
    *head = start;
}

int main()
{
    node *head = NULL;
    int arr[] = {1, 100, 2, 4, 102, 104, 10, 8};
    int i, size = sizeof(arr) / sizeof(int);

    for (i = 0; i < size; i++)
        add_nodeint(&head, arr[i]);
    print_list(head); // 8 -> 10 -> 104 -> 102 -> 4 -> 2 -> 100 -> 1
    partition(&head, 50);
    print_list(head); // 1 -> 2 -> 4 -> 10 -> 8 -> 104 -> 102 -> 100

    return 0;
}