TreeNode = __import__('tree').TreeNode


def check_balanced(root):
    """
    Determines if a binary tree is balanced
    """
    return check_height(root) != float("-inf")


def check_height(root):
    """
    Calculates differences between heights of left and right nodes.
    If difference is greater than 1, return INT_MIN */
    """
    if root == None:
        return -1
    left_height = check_height(root.left)
    if left_height == float("-inf"):
        return float("-inf")
    right_height = check_height(root.right)
    if right_height == float("-inf"):
        return float("-inf")
    difference = left_height - right_height
    if abs(difference) > 1:
        return float("-inf")
    return max(left_height, right_height) + 1


n1 = TreeNode(1)
n2 = TreeNode(2)
n1.left = n2
n3 = TreeNode(3)
n1.right = n3
n4 = TreeNode(4)
n2.left = n4
n5 = TreeNode(5)
n2.right = n5
n6 = TreeNode(6)
n7 = TreeNode(7)
n3.left = n6
# n3.right = n7 # will make it balanced
n8 = TreeNode(8)
n9 = TreeNode(9)
n4.left = n8
n4.right = n9
n10 = TreeNode(10)
n11 = TreeNode(11)
n5.left = n10
n5.right = n11
n12 = TreeNode(12)
n13 = TreeNode(13)
n6.left = n12
n6.right = n13
n15 = TreeNode(15)

print(check_balanced(n1))  # false
