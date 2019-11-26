const { TreeNode } = require('./tree')

/* LINK TO PARENTS EXIST */

/* Finds the first common ancestor of two nodes in a binary tree
 * if there are links to parents */
const firstCommonAncestor = (first, second) => {
  const delta = findDepth(first) - findDepth(second)
  long = delta > 0 ? first : second
  short = delta > 0 ? second : first
  new_long = moveUpBy(long, Math.abs(delta))
  while (new_long && short && new_long != short) {
    new_long = new_long.parent
    short = short.parent
  }
  return !new_long || !short ? null : short
}

/* Moves a node up by a given number of nodes */
const moveUpBy = (node, delta) => {
  while (delta && node) {
    node = node.parent
    delta--
  }
  return node
}

/* Finds the depth from a node of a binary tree */
const findDepth = node => {
  depth = 0
  while (node) {
    node = node.parent
    depth++
  }
  return depth
}

/* LINK TO PARENTS DOES NOT EXIST */

/* Finds the first common ancestor of two nodes in a binary tree
 * if there are no links to parents */
const commonAncestor = (root, first, second) => {
  if (!covers(root, first) || !covers(root, second)) return null
  return commonAncestorHelper(root, first, second)
}

/* Helper */
const commonAncestorHelper = (root, first, second) => {
  if (!root || root === first || root === second) return root
  is_first_left = covers(root.left, first)
  is_second_left = covers(root.left, second)
  if (is_first_left != is_second_left) return root
  const childSide = is_first_left ? root.left : root.right
  return commonAncestorHelper(childSide, first, second)
}

/* Determines if a node has another node in subtree */
const covers = (root, node) => {
  if (!root) return false
  if (root === node) return true
  return covers(root.left, node) || covers(root.right, node)
}

const n1 = new TreeNode(1)
const n2 = n1.addLeft(2)
const n3 = n1.addRight(3)
const n4 = n2.addLeft(4)
const n5 = n2.addRight(5)
const n6 = n3.addLeft(6)
const n7 = n3.addRight(7)
const n8 = n4.addLeft(8)
const n9 = n4.addRight(9)
const n10 = n5.addLeft(10)
const n11 = n5.addRight(11)
const n12 = n6.addLeft(12)
const n13 = n6.addRight(13)
const n14 = n7.addLeft(14)
const n15 = n7.addRight(15)

console.log(firstCommonAncestor(n15, n8).value) // 1
console.log(firstCommonAncestor(n11, n9).value) // 2
console.log(firstCommonAncestor(n12, n13).value) // 6

console.log(commonAncestor(n1, n15, n8).value) // 1
console.log(commonAncestor(n1, n11, n9).value) // 2
console.log(commonAncestor(n1, n12, n13).value) // 6
