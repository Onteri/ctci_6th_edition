TreeNode = __import__('tree').TreeNode


def validate_bst_helper(root, minimum, maximum):
    """
    Helper
    """
    if not root:
        return True
    if (minimum and root.value < minimum) or (maximum and root.value > maximum):
        return False
    if not validate_bst_helper(root.left, minimum, root.value) or \
       not validate_bst_helper(root.right, root.value, maximum):
        return False
    return True


def validate_bst(root):
    """
    Validates that a binary tree is a binary search tree
    """
    return validate_bst_helper(root, None, None)


n15 = TreeNode(15)
n12 = TreeNode(12)
n15.left = n12
n22 = TreeNode(22)
n15.right = n22
n11 = TreeNode(11)
n12.left = n11
n14 = TreeNode(14)
n12.right = n14
n16 = TreeNode(16)
n30 = TreeNode(30)
n22.left = n16
n22.right = n30
# n22.right = TreeNode(17) # False

print(validate_bst(n15))  # True
