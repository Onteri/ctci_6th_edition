#ifndef BINARY_SEARCH_TREE
#define BINARY_SEARCH_TREE

#include "tree.h"

/* Inserts a node onto another node */
void add_node(tree_node *first, tree_node *second)
{
    /* insert in left side */
    if (first->value < second->value)
    {
        /* insert in right side */
        if (!first->right)
        {
            /* if right node does not exist, insert */
            first->right = second;
            second->parent = first;
        }
        else
            /* recurse */
            add_node(first->right, second);
    }
    else
    {
        /* insert in right side */
        if (!first->left)
        {
            /* if left node does not exist, insert */
            first->left = second;
            second->parent = first;
        }
        else
            /* recurse */
            add_node(first->left, second);
    }
}

/* Inserts a node into a Binary Search Tree */
tree_node *insert(tree_node **root, int value)
{
    tree_node *new_node;

    new_node = create_node(value);
    if (*root)
        add_node(*root, new_node);
    else
        *root = new_node;
    return new_node;
}

#endif