#include "singly_linked_lists.h"

class LinkedList2_8 : public LinkedList
{
public:
    bool is_circular();
};

/** 
 * Determines if linked list is circular
 * O(n) solution
 */
bool LinkedList2_8::is_circular()
{
    Node *hare, *tortoise;

    hare = tortoise = this->head;
    while (hare && hare->next)
    {
        hare = hare->next->next;
        tortoise = tortoise->next;
        if (hare == tortoise)
            return true;
    }
    return false;
}

int main()
{
    LinkedList2_8 *ll = new LinkedList2_8();
    Node *n1 = ll->add_node(1);
    ll->add_node(2);
    ll->add_node(4);
    ll->add_node(8);
    ll->add_node(16);
    Node *n32 = ll->add_node(32);
    ll->print_list();                  // 32-> 16-> 8-> 4-> 2-> 1
    cout << ll->is_circular() << endl; // 0
    n1->next = n32;
    cout << ll->is_circular() << endl; // 1
}