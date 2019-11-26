class BinarySearchTree {
  /* Binary Search Tree constructor */
  constructor() {
    this.root = null
    this.size = 0
  }

  /* Inserts a node into a Binary Search Tree */
  insert(value) {
    const newNode = new TreeNode(value)
    if (!this.root) this.root = newNode
    else this.addNode(this.root, newNode)
    this.size++
    return newNode
  }

  /* Inserts a node onto another node */
  addNode(node, newNode) {
    if (newNode.value <= node.value) {
      /* insert in left side */
      if (!node.left) {
        /* if left node does not exist, insert */
        newNode.parent = node
        node.left = newNode
      } else {
        /* recurse */
        this.addNode(node.left, newNode)
      }
    } else {
      /* insert in right side */
      if (!node.right) {
        /* if right node does not exist, insert */
        newNode.parent = node
        node.right = newNode
      } else {
        /* recurse */
        this.addNode(node.right, newNode)
      }
    }
  }
}

module.exports = {
  BinarySearchTree
}
