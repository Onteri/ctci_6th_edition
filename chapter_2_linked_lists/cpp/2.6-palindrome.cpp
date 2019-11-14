#include "singly_linked_lists.h"
#include <vector>

class LinkedList2_6 : public LinkedList
{
public:
  bool is_palindrome();
};

/** 
 * Determines if a linked list is a palindrome
 * O(n) time and space complexity
 */
bool LinkedList2_6::is_palindrome()
{
  Node *curr;
  int mid;
  vector<int> stack;

  mid = this->length / 2;
  curr = this->head;
  while (mid)
  {
    stack.push_back(curr->value);
    curr = curr->next;
    mid--;
  }
  if (this->length & 1)
    /* move pointer one node if list length is odd */
    curr = curr->next;
  while (curr)
  {
    if (curr->value != stack.back())
      return false;
    stack.pop_back();
    curr = curr->next;
  }
  return true;
}

int main()
{
  LinkedList2_6 *ll = new LinkedList2_6();
  int keys[] = {1, 2, 4, 5, 4, 2, 1};
  int len = sizeof(keys) / sizeof(int);
  for (int i = 0; i < len; i++)
    ll->add_node(keys[i]);
  ll->print_list();                    // 1 -> 2 -> 4 -> 5 -> 4 -> 2 -> 1
  cout << ll->is_palindrome() << endl; // 1

  LinkedList2_6 *ll2 = new LinkedList2_6();
  int keys2[] = {1, 2, 4, 4, 2, 1};
  len = sizeof(keys2) / sizeof(int);
  for (int i = 0; i < len; i++)
    ll2->add_node(keys2[i]);
  ll2->print_list();                    // 1 -> 2 -> 4 -> 4 -> 2 -> 1
  cout << ll2->is_palindrome() << endl; // 1

  LinkedList2_6 *ll3 = new LinkedList2_6();
  int keys3[] = {1, 2, 4, 5, 6, 4, 2, 1};
  len = sizeof(keys3) / sizeof(int);
  for (int i = 0; i < len; i++)
    ll3->add_node(keys3[i]);
  ll3->print_list();                    // 1 -> 2 -> 4 -> 6 -> 5 -> 4 -> 2 -> 1
  cout << ll3->is_palindrome() << endl; // 0

  return 0;
}