#include "singly_linked_lists.h"

class LinkedList2_3 : public LinkedList
{
public:
  void delete_mid_node(Node *mid);
};

/**
 * Deletes a node in the middle of a linked list.
 * O(n) time complexity.
 */
void LinkedList2_3::delete_mid_node(Node *mid)
{
  Node *next_node = mid->next;
  mid->value = next_node->value;
  mid->next = next_node->next;
  delete next_node;
}

int main()
{
  LinkedList2_3 *ll = new LinkedList2_3();
  ll->add_node(1);
  ll->add_node(2);
  ll->add_node(4);
  Node *n8 = ll->add_node(8);
  ll->add_node(16);
  ll->add_node(32);
  ll->print_list(); // 32 -> 16 -> 8 -> 4 -> 2 -> 1
  ll->delete_mid_node(n8);
  ll->print_list(); // 32 -> 16 -> 4 -> 2 -> 1
  delete ll;

  return 0;
}