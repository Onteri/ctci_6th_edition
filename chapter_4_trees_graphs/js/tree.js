class TreeNode {
  /* Tree Node constructor */
  constructor(value) {
    this.value = value
    this.left = null
    this.right = null
    this.parent = null
  }

  addLeft(value) {
    /* Adds a node to the left */
    const new_node = new TreeNode(value)
    new_node.parent = this
    this.left = new_node
    return new_node
  }

  addRight(value) {
    /* Adds a node to the right */
    const new_node = new TreeNode(value)
    new_node.parent = this
    this.right = new_node
    return new_node
  }
}

/* Prints current node before child nodes */
const preOrderTraversal = node => {
  if (!node) return
  console.log(node.value)
  preOrderTraversal(node.left)
  preOrderTraversal(node.right)
}

/* Prints left nodes, current node, and then right nodes */
const inOrderTraversal = node => {
  if (!node) return
  inOrderTraversal(node.left)
  console.log(node.value)
  inOrderTraversal(node.right)
}

/* Visits child nodes before current node */
const postOrderTraversal = node => {
  if (!node) return
  postOrderTraversal(node.left)
  postOrderTraversal(node.right)
  console.log(node.value)
}

module.exports = {
  TreeNode,
  preOrderTraversal,
  inOrderTraversal,
  postOrderTraversal
}
