/* Returns the next in-order successive node */
const nextSuccessor = node => {
  // if node has right child, traverse down and left
  if (node.right) return leftMostChild(node.right)
  let q = node
  let x = q.parent
  /* Traverse up to first parent whose right child
   * is not previous parent */
  while (x != null && x.left != q) {
    q = x
    x = x.parent
  }
  return x
}

/* Traverse to most left child node */
const leftMostChild = node => {
  if (!node) return null
  while (node.left) node = node.left
  return node
}

bst = new BST()
bst.insert(20)
bst.insert(10)
bst.insert(30)
let bst5 = bst.insert(5)
bst.insert(3)
bst.insert(7)
bst.insert(15)
let bst17 = bst.insert(17)

console.log(nextSuccessor(bst5))
/*
TreeNode {
  value: 7,
  left: null,
  right: null,
  parent: ... }
*/
console.log(nextSuccessor(bst17))
/*
TreeNode {
  value: 20,
  left:
   TreeNode {
     value: 10,
     left:
      TreeNode {
        value: 5,
        left: [TreeNode],
        right: [TreeNode],
        parent: [Circular] },
     right:
      TreeNode { value: 15, left: null, right: [TreeNode], parent: [Circular] },
     parent: [Circular] },
  right:
   TreeNode { value: 30, left: null, right: null, parent: [Circular] },
  parent: null }
 */
