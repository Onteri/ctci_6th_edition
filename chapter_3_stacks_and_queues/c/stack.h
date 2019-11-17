#ifndef STACK
#define STACK

#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

// A structure to represent a stack
typedef struct StackNode
{
    int value;
    struct StackNode *next;
} node;

node *newNode(int value)
{
    node *stackNode = malloc(sizeof(node));
    stackNode->value = value;
    stackNode->next = NULL;
    return stackNode;
}

int isEmpty(node *root)
{
    return !root;
}

void push(node **root, int value)
{
    node *stackNode = newNode(value);
    stackNode->next = *root;
    *root = stackNode;
}

int pop(node **root)
{
    node *temp;
    int popped;

    if (isEmpty(*root))
    {
        printf("cannot pop...empty stack!\n");
        return INT_MIN;
    }
    temp = *root;
    *root = temp->next;
    popped = temp->value;
    free(temp);

    return popped;
}

int peek(node *root)
{
    if (isEmpty(root))
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

#endif