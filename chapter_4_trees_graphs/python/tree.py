class TreeNode:
    def __init__(self, value):
        """
        Tree constructor
        """
        self.value = value
        self.parent = None
        self.left = None
        self.right = None


def pre_order_traversal(node):
    """
    Prints current node before child nodes
    """
    if not node:
        return
    print(node.value)
    pre_order_traversal(node.left)
    pre_order_traversal(node.right)


def in_order_traversal(node):
    """
    Prints left nodes, current node, and then right nodes
    """
    if not node:
        return
    in_order_traversal(node.left)
    print(node.value)
    in_order_traversal(node.right)


def post_order_traversal(node):
    """
    Visits child nodes before current node
    """
    if not node:
        return
    post_order_traversal(node.left)
    post_order_traversal(node.right)
    print(node.value)
