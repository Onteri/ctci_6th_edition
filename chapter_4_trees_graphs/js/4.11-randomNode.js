const { TreeNode } = require('./tree')
const { BinarySearchTree } = require('./binarySearchTree')

class TreeNode4_11 extends TreeNode {
  constructor(value) {
    /* TreeNode constructor with size attribute */
    super(value)
    this.size = 1
  }

  insertInOrder(value) {
    /* Inserts a node into correct place in Binary Search Tree */
    if (value < this.value) {
      if (!this.left) this.left = new TreeNode4_11(value)
      else this.left.insertInOrder(value)
    } else {
      if (!this.right) this.right = new TreeNode4_11(value)
      else this.right.insertInOrder(value)
    }
    this.size++
  }

  getIthNode(index) {
    /* Retrieves the node at guven index */
    const leftSide = this.left == null ? 0 : this.left.size
    if (index < leftSide) return this.left.getIthNode(index)
    else if (index == leftSide) return this
    else return this.right.getIthNode(index - (leftSide + 1))
  }
}

class BinarySearchTree4_11 extends BinarySearchTree {
  /* Inserts a node into correct place in Binary Search Tree */
  insertInOrder(value) {
    if (!this.root) this.root = new TreeNode4_11(value)
    else this.root.insertInOrder(value)
    this.size++
  }

  /* Retrieves random node in Binary Search Tree */
  getRandomNode() {
    if (!this.root) return null
    /* Get random index */
    const index = Math.floor(Math.random() * this.size)
    return this.root.getIthNode(index)
  }
}

const bst = new BinarySearchTree4_11()
bst.insertInOrder(20)
bst.insertInOrder(10)
bst.insertInOrder(30)
bst.insertInOrder(5)
bst.insertInOrder(3)
bst.insertInOrder(7)
bst.insertInOrder(35)
bst.insertInOrder(15)
bst.insertInOrder(17)
const arr = Array(10)
let string = ''
for (let i of arr) string += bst.getRandomNode().value + ' '
console.log(string)
/* 5 10 35 30 7 20 30 17 10 10 */
