#include "singly_linked_lists.h"

/**
 * Prints all elements of a singly linked list.
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
 * Returns the number of elements in a singly linked list.
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
 * Adds a new node to the head of a singly linked list.
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
 * Deletes a node at a given index.
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
 * Frees a singly linked list.
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
 * Reverses a singly linked list.
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
 * Compares two singly linked lists for differences.
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
