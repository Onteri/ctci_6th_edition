#include "tree.h"
#include <climits>

/* Calculates differences between heights of left and right nodes.
 * If difference is greater than 1, return INT_MIN */
int check_height(TreeNode *root)
{
    int left_height, right_height, difference;

    if (!root)
        return -1;
    left_height = check_height(root->left);
    if (left_height == INT_MIN)
        return INT_MIN;
    right_height = check_height(root->right);
    if (right_height == INT_MIN)
        return INT_MIN;
    difference = left_height - right_height;
    if (abs(difference) > 1)
        return INT_MIN;
    return max(left_height, right_height) + 1;
}

/* Determines if a binary tree is balanced */
bool check_balanced(TreeNode *root)
{
    return check_height(root) != INT_MIN;
}

int main()
{
    TreeNode *t1 = new TreeNode(1);
    TreeNode *t2 = new TreeNode(2);
    TreeNode *t3 = new TreeNode(3);
    t1->left = t2;
    t1->right = t3;
    TreeNode *t4 = new TreeNode(4);
    TreeNode *t5 = new TreeNode(5);
    t2->left = t4;
    t2->right = t5;
    TreeNode *t6 = new TreeNode(6);
    TreeNode *t7 = new TreeNode(7);
    t3->left = t6;
    t3->right = t7;

    cout << check_balanced(t1) << endl; // 1

    TreeNode *t8 = new TreeNode(8);
    TreeNode *t9 = new TreeNode(9);
    t6->right = t8;
    t8->right = t9;

    cout << check_balanced(t1) << endl; // 0

    return 0;
}
