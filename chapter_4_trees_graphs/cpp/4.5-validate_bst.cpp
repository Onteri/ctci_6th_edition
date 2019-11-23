#include "tree_node.h"

/* Helper */
bool validate_bst_helper(TreeNode *root, int *min, int *max)
{
    if (!root)
        return true;
    if ((min && root->value <= *min) || (max && root->value > *max))
        return false;
    if (!validate_bst_helper(root->left, min, &root->value) ||
        !validate_bst_helper(root->right, &root->value, max))
        return false;
    return true;
}

/* Validates that a binary tree is a binary search tree */
bool validate_bst(TreeNode *root)
{
    return validate_bst_helper(root, nullptr, nullptr);
}

int main()
{
    TreeNode *t1 = new TreeNode(20);
    TreeNode *t2 = new TreeNode(10);
    TreeNode *t3 = new TreeNode(30);
    t1->left = t2;
    t1->right = t3;
    TreeNode *t4 = new TreeNode(5);
    TreeNode *t5 = new TreeNode(15);
    t2->left = t4;
    t2->right = t5;
    TreeNode *t6 = new TreeNode(25);
    // TreeNode *t7 = new TreeNode(27); // 0
    TreeNode *t7 = new TreeNode(50);
    t3->left = t6;
    t3->right = t7;

    cout << validate_bst(t1) << endl; // 1

    return 0;
}
