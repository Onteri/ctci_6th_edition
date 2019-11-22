TreeNode = __import__('binary_search_tree').BinarySearchTree


class BinarySearchTree:
    def __init__(self):
        """
        Binary Search Tree constructor
        """
        self.root = None
        self.size = 0

    def insert(self, value):
        """
        Inserts a node into a Binary Search Tree
        """
        node = TreeNode(value)
        if not self.root:
            self.root = node
        else:
            self.add_node(self.root, node)
        self.size += 1
        return node

    def add_node(self, node, new_node):
        """
        Inserts a node onto another node
        """
        if new_node.value <= node.value:
            # insert in left side
            if not node.left:
                # if left node does not exist, insert
                node.left = new_node
                new_node.parent = node
            else:
                # recurse
                self.add_node(node.left, new_node)
        else:
            # insert in right side
            if not node.right:
                # if right node does not exist, insert
                node.right = new_node
                new_node.parent = node
            else:
                # recurse
                self.add_node(node.right, new_node)
