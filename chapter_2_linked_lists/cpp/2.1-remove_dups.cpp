#include <iostream>
#include "header.h"

class LinkedList2_1 : public LinkedList {
public:
    void remove_dups();
};

/** 
 * Delete nodes with duplicate values in a linked list
 * O(n**2) time complexity 
 */
void LinkedList2_1::remove_dups()
{
    return;
}


int main() {
  LinkedList2_1 *ll = new LinkedList2_1();
  ll->add_node(1);
  ll->add_node(2);
  ll->add_node(4);
  ll->add_node(8);
  ll->add_node(16);
  ll->add_node(32);
  ll->print_list(); // 32-> 16-> 8-> 4-> 2-> 1
}