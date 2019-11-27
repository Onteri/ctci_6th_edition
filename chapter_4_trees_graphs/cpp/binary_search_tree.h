#ifndef BINARY_SEARCH_TREE

#include <iostream>
#include "tree.h"

using namespace std;

class BinarySearchTree
{
public:
    TreeNode *root;

    BinarySearchTree();
    TreeNode *insert(int value);

private:
    int size;

    void add_node(TreeNode *node, TreeNode *new_node);
};

/* Binary Search Tree constructor */
BinarySearchTree::BinarySearchTree()
{
    this->root = nullptr;
    this->size = 0;
}

/* Inserts a node into a Binary Search Tree */
TreeNode *BinarySearchTree::insert(int value)
{
    TreeNode *n;

    n = new TreeNode(value);
    if (!this->root)
        this->root = n;
    else
        this->add_node(this->root, n);
    this->size++;
    return n;
}

/* Inserts a node onto another node */
void BinarySearchTree::add_node(TreeNode *node, TreeNode *new_node)
{
    if (node->value < new_node->value)
    {
        /* insert in right side */
        if (!node->right)
        {
            /* if right node does not exist, insert */
            node->right = new_node;
            new_node->parent = node;
        }
        else
            /* recurse */
            this->add_node(node->right, new_node);
    }
    else
    {
        /* insert in left side */
        if (!node->left)
        {
            /* if left node does not exist, insert */
            node->left = new_node;
            new_node->parent = node;
        }
        else
            /* recurse */
            this->add_node(node->left, new_node);
    }
}

#endif