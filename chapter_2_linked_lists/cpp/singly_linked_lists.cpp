#include <iostream>
#include "singly_linked_lists.h"

using namespace std;

/**
 * Node constructor.
 */
Node::Node(int value)
{
    this->value = value;
    this->next = nullptr;
};

/**
 * Singly linked list constructor.
 */
LinkedList::LinkedList()
{
    this->head = nullptr;
    this->length = 0;
}

/**
 * Adds a new node to the head of a singly linked list.
 */
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

/**
 * Prints all elements of a singly linked list.
 */
void LinkedList::print_list()
{
    Node *curr = this->head;
    while (curr->next)
    {
        cout << curr->value << " -> ";
        curr = curr->next;
    }
    cout << curr->value << endl;
}

/**
 * Deletes a node at a given index.
 */
void LinkedList::delete_node(int index)
{
    if (index < 0 || index >= this->length)
        throw;

    Node *prev = nullptr;
    Node *curr = this->head;
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