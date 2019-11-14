#include "singly_linked_lists.h"
#include <unordered_set>

class LinkedList2_1 : public LinkedList
{
public:
    void remove_dups();
};

/** 
 * Delete nodes with duplicate values in a linked list
 * O(n) time complexity 
 */
void LinkedList2_1::remove_dups()
{
    unordered_set<int> set;
    int index;
    Node *curr, *prev;

    curr = this->head;
    prev = nullptr;

    while (curr)
    {
        /* if found in set */
        if (set.find(curr->value) != set.end())
        {
            prev->next = curr->next;
            delete curr;
        }
        else
        {
            /* add to set */
            set.insert(curr->value);
            prev = curr;
        }
        curr = prev->next;
    }
}

int main()
{
    LinkedList2_1 *ll = new LinkedList2_1();
    int keys[] = {1, 1, 2, 4, 4, 8, 16, 32, 32};
    int size = sizeof(keys) / sizeof(int);

    for (int i = 0; i < size; i++)
        ll->add_node(keys[i]);
    ll->print_list(); // 32 -> 32 -> 16 -> 8 -> 4 -> 4 -> 2 -> 1 -> 1
    ll->remove_dups();
    ll->print_list(); // 32 -> 16 -> 8 -> 4 -> 2 -> 1
}