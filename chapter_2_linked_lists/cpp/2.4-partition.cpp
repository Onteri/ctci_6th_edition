#include <iostream>
#include "header.h"

class LinkedList2_4 : public LinkedList {
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
        } else {
            end->next = curr;
            end = curr;
        }
        curr = next;
    }
    end->next = NULL;
    this->head = start;
}


int main() {
  LinkedList2_4 *ll = new LinkedList2_4();
  ll->add_node(1);
  ll->add_node(100);
  ll->add_node(101);
  ll->add_node(2);
  ll->add_node(3);
  ll->add_node(103);
  ll->print_list(); // 32-> 16-> 8-> 4-> 2-> 1
  ll->partition(50);
  ll->print_list(); // 1-> 2-> 3-> 103-> 101-> 100
}