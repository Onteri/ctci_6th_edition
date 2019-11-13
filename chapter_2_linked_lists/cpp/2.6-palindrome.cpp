#include <iostream>
#include "header.h"

class LinkedList2_6 : public LinkedList {
public:
    bool is_palindrome();
};

/** 
 * Determines if a linked list is a palindrome
 * O(n) time and space complexity
 */
bool *LinkedList2_6::is_palindrome();
{
    return 0;
}


int main() {
  LinkedList2_6 *ll = new LinkedList2_6();
  ll->add_node(1);
  ll->add_node(2);
  ll->add_node(4);
  ll->add_node(8);
  ll->add_node(16);
  ll->add_node(32);
  ll->print_list(); // 32-> 16-> 8-> 4-> 2-> 1
}