TreeNode = __import__('tree').TreeNode
pre_order_traversal = __import__('tree').pre_order_traversal


def create_minimal_bst(arr):
    """
    Creates a binary search tree with minimal height
    """
    return create_minimal_bst_helper(arr, 0, len(arr) - 1)


def create_minimal_bst_helper(arr, start, end):
    """
    Helper 
    """
    if start > end:
        return None
    mid = (start + end) // 2
    node = TreeNode(arr[mid])
    node.left = create_minimal_bst_helper(arr, start, mid - 1)
    node.right = create_minimal_bst_helper(arr, mid + 1, end)
    return node


arr = [1, 4, 6, 8, 9, 12, 19, 21]
root = create_minimal_bst(arr)
pre_order_traversal(root)
"""
8
4
1
6
12
9
19
21
"""
