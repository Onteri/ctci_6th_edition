class BinarySeachTree {
  constructor() {
    this.root = null
  }

  insert(value) {
    const newNode = new TreeNode(value)
    if (!this.root) this.root = newNode
    else this.addNode(this.root, newNode)
    return newNode
  }

  addNode(node, newNode) {
    if (newNode.value < node.value) {
      if (!node.left) {
        newNode.parent = node
        node.left = newNode
      } else {
        this.addNode(node.left, newNode)
      }
    } else {
      if (!node.right) {
        newNode.parent = node
        node.right = newNode
      } else {
        this.addNode(node.right, newNode)
      }
    }
  }
}

modules.export = {
  BinarySeachTree
}
