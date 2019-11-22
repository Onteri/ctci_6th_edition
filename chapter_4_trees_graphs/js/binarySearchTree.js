class BinarySeachTree {
  constructor() {
    /* Binary Search Tree constructor */
    this.root = null
    this.size = 0
  }

  insert(value) {
    /* Inserts a node into a Binary Search Tree */
    const newNode = new TreeNode(value)
    if (!this.root) this.root = newNode
    else this.addNode(this.root, newNode)
    this.size++
    return newNode
  }

  addNode(node, newNode) {
    /* Inserts a node onto another node */
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

modules.export = {
  BinarySeachTree
}
