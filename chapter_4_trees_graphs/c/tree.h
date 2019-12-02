#ifndef TREE_NODE
#define TREE_NODE

#define MAX(x, y) ((x) > (y) ? (x) : (y))

#include <stdio.h>
#include <stdlib.h>

typedef struct tree_node
{
    int value;
    struct tree_node *left;
    struct tree_node *right;
    struct tree_node *parent;
} tree_node;

/**
 * Tree Node constructor.
 */
tree_node *create_node(int value)
{
    tree_node *new_node;

    new_node = malloc(sizeof(tree_node));
    new_node->left = NULL;
    new_node->right = NULL;
    new_node->parent = NULL;
    new_node->value = value;
    return new_node;
}

/**
 * Adds a node to the left.
 */
tree_node *add_left(tree_node *root, int value)
{
    tree_node *new_node;

    new_node = create_node(value);
    new_node->parent = root;
    root->left = new_node;
    return new_node;
}

/**
 * Adds a node to the right.
 */
tree_node *add_right(tree_node *root, int value)
{
    tree_node *new_node;

    new_node = create_node(value);
    new_node->parent = root;
    root->right = new_node;
    return new_node;
}

/**
 * Returns the height of the tree from the root.
 */
int find_height(tree_node *root)
{
    int left, right;

    if (!root)
        return 0;
    left = find_height(root->left);
    right = find_height(root->right);
    return MAX(left, right) + 1;
}

/**
 * Prints current node before child nodes.
 */
void pre_order_traversal(tree_node *root)
{
    if (!root)
        return;
    printf("%i ", root->value);
    pre_order_traversal(root->left);
    pre_order_traversal(root->right);
}

#endif