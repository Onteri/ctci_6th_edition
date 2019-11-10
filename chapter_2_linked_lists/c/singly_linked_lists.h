#ifndef SINGLY_LINKED_LISTS
#define SINGLY_LINKED_LISTS

#include <stdio.h>
#include <stdlib.h>

/**
 * struct sll_node - singly linked list
 * @n: integer
 * @next: points to the next node
 *
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
    node *newNode = (node *)malloc(sizeof(node));

    if (!head || !newNode)
        return (NULL);
    newNode->n = n;
    newNode->next = NULL;
    if (*head)
        newNode->next = *head;
    *head = newNode;
    return (newNode);
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

#endif