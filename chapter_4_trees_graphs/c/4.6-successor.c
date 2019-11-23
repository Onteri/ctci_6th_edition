#include "tree.h"
#include "binary_search_tree.h"

/* Traverse to most left child node */
node *left_most_child(node *root)
{
    node *curr;

    curr = root;
    while (curr->left)
        curr = curr->left;
    return curr;
}

/* Returns the next in-order successive node */
node *next_successor(node *tree_node)
{
    node *child, *parent;

    if (!tree_node)
        return NULL;
    /* If node has right child, traverse down and left */
    if (tree_node->right)
        return left_most_child(tree_node->right);
    child = tree_node;
    parent = child->parent;
    /* Traverse up to first parent whose left child
     * is not original node or previous parent */
    while (parent && parent->left != child)
    {
        child = parent;
        parent = parent->parent;
    }
    return parent;
}

int main(void)
{
    node *root = NULL;
    node *n5, *n15;

    insert(&root, 20);
    insert(&root, 10);
    insert(&root, 30);
    n5 = insert(&root, 5);
    insert(&root, 3);
    insert(&root, 7);
    n15 = insert(&root, 15);
    insert(&root, 17);

    in_order_traversal(root);
    /* 20 10 5 3 7 15 17 30 */
    printf("\n%i", next_successor(n5)->value);    // 7
    printf("\n%i\n", next_successor(n15)->value); // 17

    return 0;
}