class TreeNode {
  /* Tree constructor */
  constructor(value) {
    this.value = value
    this.left = null
    this.right = null
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

/* Visits child nodes before curret node */
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
