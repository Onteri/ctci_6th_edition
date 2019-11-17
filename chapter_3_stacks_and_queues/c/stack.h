#ifndef STACK
#define STACK

#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

// A structure to represent a stack
typedef struct stack_node
{
    int value;
    struct stack_node *next;
} node;

node *new_node(int value)
{
    node *stack_node = malloc(sizeof(node));
    stack_node->value = value;
    stack_node->next = NULL;
    return stack_node;
}

int is_empty(node *root)
{
    return !root;
}

void push(node **root, int value)
{
    node *stack_node = new_node(value);
    stack_node->next = *root;
    *root = stack_node;
}

int pop(node **root)
{
    node *temp;
    int popped;

    if (is_empty(*root))
    {
        printf("cannot pop...empty stack!\n");
        exit(1);
    }
    temp = *root;
    *root = temp->next;
    popped = temp->value;
    free(temp);

    return popped;
}

int peek(node *root)
{
    if (is_empty(root))
        return INT_MAX;
    return root->value;
}

void print_stack(node *root)
{
    while (root)
    {
        printf("%i ", root->value);
        root = root->next;
    }
    printf("\n");
}

void free_stack(node **root)
{
    node *current;
    node *tmp;

    if (!root)
        return;
    current = *root;
    while (current)
    {
        tmp = current;
        current = tmp->next;
        free(tmp);
    }
    *root = NULL;
    root = NULL;
}

#endif