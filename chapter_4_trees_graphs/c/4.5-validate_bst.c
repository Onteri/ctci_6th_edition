#include "tree.h"
#include "bst.h"

/* Helper */
int validate_bst_helper(node *tree_node, int *min, int *max)
{
    if (!tree_node)
        return 1;
    if ((min && tree_node->value < *min) || (max && tree_node->value > *max))
        return 0;
    if (!validate_bst_helper(tree_node->left, min, &tree_node->value) || !validate_bst_helper(tree_node->right, &tree_node->value, max))
        return 0;
    return 1;
}

/* Validates that a binary tree is a binary search tree */
int validate_bst(node *root)
{
    return validate_bst_helper(root, NULL, NULL);
}

int main(void)
{
    node *root = NULL;
    node *n5, *n15, *n12;

    insert(&root, 20);
    insert(&root, 10);
    insert(&root, 30);
    n5 = insert(&root, 5);
    insert(&root, 3);
    insert(&root, 7);
    n15 = insert(&root, 15);
    insert(&root, 17);

    printf("%i\n", validate_bst(root)); // 1

    n12 = create_node(12);
    n15->right = n12;

    printf("%i\n", validate_bst(root)); // 0

    return 0;
}