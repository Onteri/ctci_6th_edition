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
};

/* Tree constructor */
TreeNode::TreeNode(int value)
{
    this->value = value;
    this->left = nullptr;
    this->right = nullptr;
    this->parent = nullptr;
};

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