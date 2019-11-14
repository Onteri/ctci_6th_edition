#include "singly_linked_lists.h"

class LinkedList2_2 : public LinkedList
{
public:
    Node *kth_to_last(int index);
};

/** 
 * Returns the kth element from last node
 * O(n) time complexity
 */
Node *LinkedList2_2::kth_to_last(int index)
{
    Node *curr, *kth;

    curr = kth = this->head;
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
    LinkedList2_2 *ll = new LinkedList2_2();
    int keys[] = {1, 2, 4, 8, 16, 32};
    int i, size = sizeof(keys) / sizeof(int);

    for (i = 0; i < size; i++)
        ll->add_node(keys[i]);
    ll->print_list(); // 32-> 16-> 8-> 4-> 2-> 1
    Node *ptr = ll->kth_to_last(2);
    cout << ptr->value << endl; // 2
}