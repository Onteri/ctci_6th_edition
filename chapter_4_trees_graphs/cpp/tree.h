#ifndef TREE_NODE

#include <iostream>

using namespace std;

class TreeNode
{
public:
    int value;
    TreeNode *left;
    TreeNode *right;
    TreeNode *parent;
    TreeNode(int value);

    TreeNode *addLeft(int value);
    TreeNode *addRight(int value);
};

/* Tree Node constructor */
TreeNode::TreeNode(int value)
{
    this->value = value;
    this->left = nullptr;
    this->right = nullptr;
    this->parent = nullptr;
};

/* Adds a node to the left */
TreeNode *TreeNode::addLeft(int value)
{
    TreeNode *new_node;

    new_node = new TreeNode(value);
    new_node->parent = this;
    this->left = new_node;
    return new_node;
}

/* Adds a node to the right */
TreeNode *TreeNode::addRight(int value)
{
    TreeNode *new_node;

    new_node = new TreeNode(value);
    new_node->parent = this;
    this->right = new_node;
    return new_node;
}

/* Prints current node before child nodes */
void pre_order_traversal(TreeNode *root)
{
    if (!root)
        return;
    cout << root->value << endl;
    pre_order_traversal(root->left);
    pre_order_traversal(root->right);
}

#endif