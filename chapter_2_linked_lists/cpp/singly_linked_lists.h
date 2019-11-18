#ifndef SINGLY_LINKED_LISTS

#include <iostream>

using namespace std;

class Node
{
public:
    int value;
    Node *next;

    Node(int value);
};

/* Node constructor */
Node::Node(int value)
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

    Node *add_node(int value);
    void print_list();
    void delete_node(int index);
};

/* Singly linked list constructor */
LinkedList::LinkedList()
{
    this->head = NULL;
    this->length = 0;
}

/* Adds a new node to the head of a singly linked list */
Node *LinkedList::add_node(int value)
{
    Node *new_node = new Node(value);
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
        cout << curr->value << " -> ";
        curr = curr->next;
    }
    cout << curr->value << endl;
}

/* Deletes a node at a given index */
void LinkedList::delete_node(int index)
{
    Node *curr, *prev;
    if (index < 0 || index >= this->length)
        throw;

    curr = this->head;
    if (index == 0)
    {
        this->head = this->head->next;
        delete curr;
        return;
    }
    if (index == this->length - 1)
    {
        while (curr->next)
        {
            prev = curr;
            curr = curr->next;
        }
        prev->next = NULL;
        delete curr;
        return;
    }
    while (index)
    {
        prev = curr;
        curr = curr->next;
        index--;
    }
    prev->next = curr->next;
    delete curr;
}

#endif