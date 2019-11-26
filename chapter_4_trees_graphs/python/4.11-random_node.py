import random

TreeNode = __import__('tree').TreeNode
BinarySearchTree = __import__('binary_search_tree').BinarySearchTree


class BinarySearchTree4_11(BinarySearchTree):
    def insert_in_order(self, value):
        """
        Inserts a node into correct place in Binary Search Tree
        """
        if not self.root:
            self.root = TreeNode4_11(value)
        else:
            self.root.insert_in_order(value)
        self.size += 1

    def get_random_node(self):
        """
        Retrieves a random node in Binary Search Tree
        """
        index = random.randint(0, self.size - 1)
        return self.root.get_ith_node(index)


class TreeNode4_11(TreeNode):
    def __init__(self, value):
        """
        TreeNode constructor with size attribute
        """
        super().__init__(value)
        self.size = 1

    def insert_in_order(self, value):
        """
        Inserts a node into correct place in Binary Search Tree
        """
        if value < self.value:
            if not self.left:
                self.left = TreeNode4_11(value)
            else:
                self.left.insert_in_order(value)
        else:
            if not self.right:
                self.right = TreeNode4_11(value)
            else:
                self.right.insert_in_order(value)
        self.size += 1

    def get_ith_node(self, index):
        """
        Retrieves the node at guven index
        """
        left_side = 0 if self.left == None else self.left.size
        if index < left_side:
            return self.left.get_ith_node(index)
        elif index == left_side:
            return self
        else:
            return self.right.get_ith_node(index - (left_side + 1))


bst = BinarySearchTree4_11()
arr = [20, 30, 10, 15, 35, 17, 5, 3, 7]
for i in arr:
    bst.insert_in_order(i)
string = []
for i in range(20):
    string.append(str(bst.get_random_node().value))
print(" ".join(string))
# 10 15 7 15 30 3 15 15 5 15 10 7 35 20 7 5 35 7 5 3
