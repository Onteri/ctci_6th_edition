#include <stdlib.h>
#include "singly_linked_lists.h"

class LinkedList2_7 : public LinkedList
{
public:
    Node *find_intersection(LinkedList2_7 *other_list);
};

/* Finds if two linked lists intersect and returns
 * the node where they first meet
 * O(n) time and space complexity */
Node *LinkedList2_7::find_intersection(LinkedList2_7 *other_list)
{
    int len1, len2, difference;
    LinkedList2_7 *longer, *shorter;
    Node *longer_start, *shorter_start;

    len1 = this->length;
    len2 = other_list->length;
    longer = len1 > len2 ? this : other_list;
    shorter = len1 > len2 ? other_list : this;
    difference = abs(len1 - len2);
    longer_start = longer->head;
    shorter_start = shorter->head;

    while (difference)
    {
        longer_start = longer_start->next;
        difference--;
    }
    while (longer_start)
    {
        if (longer_start == shorter_start)
            return longer_start;
        longer_start = longer_start->next;
        shorter_start = shorter_start->next;
    }
    return NULL;
}

int main()
{
    LinkedList2_7 *ll = new LinkedList2_7();
    ll->add_node(1);
    ll->add_node(2);
    Node *n4 = ll->add_node(4);
    ll->add_node(8);
    ll->add_node(16);
    ll->add_node(32);
    ll->print_list(); // 32-> 16-> 8-> 4-> 2-> 1

    LinkedList2_7 *ll2 = new LinkedList2_7();
    Node *n5 = ll2->add_node(5);
    n5->next = n4;
    ll2->length += 3;
    ll2->print_list();
    cout << ll->find_intersection(ll2)->value << endl; // 4

    return 0;
}