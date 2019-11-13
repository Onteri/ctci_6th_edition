#include <iostream>
#include "header.h"

class LinkedList2_2 : public LinkedList {
public:
    Node *kth_to_last(int index);
};

/** 
 * Returns the kth element from last node
 * O(n) time complexity
 */
Node *LinkedList2_2::kth_to_last(int index)
{
    Node *curr;
    Node *kth;

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


int main() {
  LinkedList2_2 *ll = new LinkedList2_2();
  ll->add_node(1);
  ll->add_node(2);
  ll->add_node(4);
  ll->add_node(8);
  ll->add_node(16);
  ll->add_node(32);
  ll->print_list(); // 32-> 16-> 8-> 4-> 2-> 1
  Node *ptr = ll->kth_to_last(2);
  cout << ptr->value << endl; // 2
}