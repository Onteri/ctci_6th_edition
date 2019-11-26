#include "tree.h"

/* LINK TO PARENTS DOES NOT EXIST */

/* Determines if a node has another node in subtree */
bool covers(GraphNode *root, GraphNode *node)
{
    if (!root)
        return false;
    if (root == node)
        return true;
    return covers(root->left, node) || covers(root->right, node);
}

/* Helper */
GraphNode *common_ancestor_helper(GraphNode *root, GraphNode *p, GraphNode *q)
{
    bool is_p_left, is_q_left;
    GraphNode *child_side;

    if (!root || root == p || root == q)
        return root;
    is_p_left = covers(root->left, p);
    is_q_left = covers(root->left, q);
    if (is_p_left != is_q_left)
        return root;
    child_side = is_p_left ? root->left : root->right;
    return common_ancestor_helper(child_side, p, q);
}

/* Finds the first common ancestor of two nodes in a binary tree
 * if there are no links to parents */
GraphNode *common_ancestor(GraphNode *root, GraphNode *p, GraphNode *q)
{
    if (!covers(root, p) || !covers(root, q))
        return nullptr;
    return common_ancestor_helper(root, p, q);
}

/* LINK TO PARENTS EXIST */

/* Finds the depth from a node of a binary tree */
unsigned int find_depth(GraphNode *node)
{
    unsigned int depth = 0;

    while (node)
    {
        node = node->parent;
        depth++;
    }
    return depth;
}

/* Moves a node up by a given number of nodes */
GraphNode *move_up_by(GraphNode *node, unsigned int delta)
{
    GraphNode *curr = node;

    while (delta && curr)
    {
        curr = curr->parent;
        delta--;
    }
    return curr;
}

/* Finds the first common ancestor of two nodes in a binary tree
 * if there are links to parents */
GraphNode *find_common_ancestor(GraphNode *p, GraphNode *q)
{
    int delta;
    GraphNode *first, *second;

    delta = find_depth(p) - find_depth(q);
    first = delta > 0 ? p : q;
    second = delta > 0 ? q : p;
    first = move_up_by(first, abs(delta));
    while (first && second && first != second)
    {
        first = first->parent;
        second = second->parent;
    }
    return first && second ? first : nullptr;
}

int main()
{
    GraphNode *solution;

    GraphNode *root = new GraphNode(1);
    GraphNode *n2 = root->addLeft(2);
    GraphNode *n3 = root->addRight(3);
    GraphNode *n4 = n2->addLeft(4);
    GraphNode *n5 = n2->addRight(5);
    GraphNode *n6 = n3->addLeft(6);
    GraphNode *n7 = n3->addRight(7);
    GraphNode *n8 = n4->addLeft(8);
    GraphNode *n9 = n4->addRight(9);
    GraphNode *n10 = n5->addLeft(10);
    GraphNode *n11 = n5->addRight(11);

    GraphNode *n15 = new GraphNode(15);

    solution = find_common_ancestor(n8, n11);
    cout << solution->value << endl; // 2
    solution = find_common_ancestor(n8, n5);
    cout << solution->value << endl; // 2
    solution = find_common_ancestor(n8, n7);
    cout << solution->value << endl; // 1
    solution = find_common_ancestor(n8, n15);
    cout << solution << endl; // 0

    solution = common_ancestor(root, n8, n11);
    cout << solution->value << endl; // 2
    solution = common_ancestor(root, n8, n5);
    cout << solution->value << endl; // 2
    solution = common_ancestor(root, n8, n7);
    cout << solution->value << endl; // 1
    solution = common_ancestor(root, n8, n15);
    cout << solution << endl; // 0
}