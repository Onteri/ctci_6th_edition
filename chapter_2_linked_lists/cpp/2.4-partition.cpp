#include "singly_linked_lists.h"

class LinkedList2_4 : public LinkedList
{
public:
    void partition(int partition);
};

/**
 * Partitions a linked list according to a number
 * All values lower than number will go on the left and 
 * all values higher and equal will go on the right
 * This solution is unstable, but performs at
 * O(n) time complexity
 */
void LinkedList2_4::partition(int partition)
{
    Node *start, *end, *curr, *next;

    start = end = curr = this->head;
    while (curr)
    {
        next = curr->next;
        if (curr->value < partition)
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
    this->head = start;
}

int main()
{
    LinkedList2_4 *ll = new LinkedList2_4();
    int keys[] = {1, 100, 101, 2, 3, 103};
    int i, size = sizeof(keys) / sizeof(int);

    for (i = 0; i < size; i++)
        ll->add_node(keys[i]);
    ll->print_list(); // 103 -> 3 -> 2 -> 101 -> 100 -> 1
    ll->partition(50);
    ll->print_list(); // 1 -> 2 -> 3 -> 103 -> 101 -> 100
}