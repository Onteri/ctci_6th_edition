#include <iostream>
#include "header.h"

class LinkedList2_5 : public LinkedList {
public:
   static Node *sum_list(Node *first_list, Node *other_list, int carry);
};

/**
 * Adds the values of two linked lists by creating a new list 
 * O(a + b) solution, a and b being lengths of respective lists
 */
Node *LinkedList2_5::sum_list(Node *first_list, Node *other_list, int carry)
{
    int value;
    Node *new_node, *next_node;
    if (!first_list && !other_list && !carry)
        return NULL;
    value = carry;
    if (first_list)
        value += first_list->value;
    if (other_list)
        value += other_list->value;
    new_node = new Node(0);
    new_node->value = value % 10;
    if (first_list || other_list)
    {
        next_node = sum_list(
            first_list ? first_list->next : NULL,
            other_list ? other_list->next : NULL,
            value >= 10 ? 1 : 0); 
        new_node->next = next_node;
    }
    return new_node;
}


int main() {
  LinkedList2_5 *ll = new LinkedList2_5();
  ll->add_node(9);
  ll->add_node(9);
  ll->add_node(9);
  ll->print_list(); // 9 -> 9 -> 9

  LinkedList2_5 *ll2 = new LinkedList2_5();
  ll2->add_node(1);
  ll2->print_list(); // 1

  Node *n = LinkedList2_5::sum_list(ll->head, ll2->head, 0);
  LinkedList2_5 *ll3 = new LinkedList2_5;
  ll3->head = n;
  ll3->print_list(); // 0-> 0-> 0-> 1
}