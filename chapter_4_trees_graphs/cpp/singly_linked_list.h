#ifndef SINGLY_LINKED_LISTS

#include <iostream>

using namespace std;

class Node
{
public:
    TreeNode *value;
    Node *next;

    Node(TreeNode *value);
};

/* Node constructor */
Node::Node(TreeNode *value)
{
    this->value = value;
    this->next = NULL;
};

class LinkedList
{
public:
    Node *head;
    int length;
    LinkedList();

    Node *add_node(TreeNode *node);
    void print_list();
};

/* Singly linked list constructor */
LinkedList::LinkedList()
{
    this->head = NULL;
    this->length = 0;
}

/* Adds a new node to the head of a singly linked list */
Node *LinkedList::add_node(TreeNode *node)
{
    Node *new_node = new Node(node);
    if (!this->head)
    {
        this->head = new_node;
    }
    else
    {
        new_node->next = this->head;
        this->head = new_node;
    }
    this->length++;
    return new_node;
}

/* Prints all elements of a singly linked list */
void LinkedList::print_list()
{
    Node *curr;
    curr = this->head;
    while (curr->next)
    {
        cout << curr->value->value << " -> ";
        curr = curr->next;
    }
    cout << curr->value->value << endl;
}

#endif