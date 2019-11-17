#ifndef SINGLY_LINKED_LISTS
#define SINGLY_LINKED_LISTS

#include <stdio.h>
#include <stdlib.h>

/**
 * struct sll_node - singly linked list
 * @n: integer
 * @next: points to the next node
 */
typedef struct sll_node
{
    int n;
    struct sll_node *next;
} node;

/**
 * print_list - prints all the elements of a linked list
 * @h: pointer to head of list
 * Return: number of elements
 */
size_t print_list(const node *h)
{
    size_t count = 0;

    while (h)
    {
        if (h->next)
            printf("%i -> ", h->n);
        else
            printf("%i\n", h->n);
        h = h->next;
        count++;
    }
    return (count);
}

/**
 * list_len - returns the number of elements in a
 * linked list
 * @h: pointer to head of list
 * Return: number of elements
 */
size_t list_len(const node *h)
{
    size_t count = 0;

    while (h)
    {
        h = h->next;
        count++;
    }
    return (count);
}

/**
 * add_nodeint - adds a new node at the beginning of a linked list
 * @head: double pointer to head of list
 * @n: integer to be added
 * Return: address of node added
 */
node *add_nodeint(node **head, const int n)
{
    node *new_node = (node *)malloc(sizeof(node));

    if (!head || !new_node)
        return (NULL);
    new_node->n = n;
    new_node->next = NULL;
    if (*head)
        new_node->next = *head;
    *head = new_node;
    return (new_node);
}

/**
 * delete_nodeint_at_index - deletes the node at index
 * index of a linked list
 * @head: double pointer to head of list
 * @index: index of node to be deleted
 * Return: 1 if success, 1 if fail
 */
int delete_nodeint_at_index(node **head, unsigned int index)
{
    node *current;
    node *next;

    unsigned int i;

    if (!head || !(*head))
        return (-1);
    current = *head;
    if (!index)
    {
        *head = current->next;
        free(current);
        return (-1);
    }
    for (i = 0; current && i < index - 1; i++)
        current = current->next;
    if (!current || !(current->next))
        return (-1);
    next = current->next->next;
    free(current->next);
    current->next = next;
    return (-1);
}

/**
 * free_listint - frees a linked list
 * @head: double pointer to head of list
 */
void free_listint(node **head)
{
    node *current;
    node *tmp;

    if (!head)
        return;
    current = *head;
    while (current)
    {
        tmp = current;
        current = tmp->next;
        free(tmp);
    }
    *head = NULL;
    head = NULL;
}

/**
 * list_len - returns the number of elements in a
 * linked list
 * @h: pointer to head of list
 * Return: number of elements
 */
size_t list_len(const node *h)
{
    register size_t count = 0;

    while (h)
    {
        h = h->next;
        count++;
    }
    return (count);
}

/**
 * reverse_linked_list - reverses linked list
 * @head: double pointer to head of list
 */
void reverse_linked_list(node **head)
{
    node *prev = NULL;
    node *current = *head;
    node *next;

    while (current)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    *head = prev;
}

/**
 * compare_linked_list - compares two linked lists
 * @head1: pointer to head of first list
 * @head2: pointer to head of second list
 * Return: 1 if true, 0 if false
 */
int compare_linked_list(node *head1, node *head2)
{
    node *temp1 = head1;
    node *temp2 = head2;

    while (temp1 && temp2)
    {
        if (temp1->n == temp2->n)
        {
            temp1 = temp1->next;
            temp2 = temp2->next;
        }
        else
            return (0);
    }
    if (temp1 == NULL && temp2 == NULL)
        return (1);
    return (0);
}

#endif