#ifndef SINGLY_LINKED_LISTS_
#define SINGLY_LINKED_LISTS_

class Node
{
public:
    int value;
    Node *next;

    Node(int value);
};

class LinkedList
{
public:
    Node *head;
    int length;
    LinkedList();

    Node *add_node(int value);
    void print_list();
    void delete_node(int index);
};

#endif