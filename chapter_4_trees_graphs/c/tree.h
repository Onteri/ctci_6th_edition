#ifndef TREE_NODE
#define TREE_NODE

#include <stdio.h>
#include <stdlib.h>

typedef struct tree_node
{
    int value;
    struct tree_node *left;
    struct tree_node *right;
    struct tree_node *parent;
} node;

/* Tree Node constructor */
node *create_node(int value)
{
    node *new_node;

    new_node = malloc(sizeof(node));
    new_node->left = NULL;
    new_node->right = NULL;
    new_node->parent = NULL;
    new_node->value = value;
    return new_node;
}

/* Prints current node before child nodes */
void pre_order_traversal(node *root)
{
    if (!root)
        return;
    printf("%i ", root->value);
    in_order_traversal(root->left);
    in_order_traversal(root->right);
}

#endif