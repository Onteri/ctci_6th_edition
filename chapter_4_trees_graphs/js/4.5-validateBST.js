const { TreeNode } = require("./tree")

/* Validates that a binary tree is a binary search tree */
const validateBST = node => {
  return validateBSTHelper(node, null, null)
}

/* Helper */
const validateBSTHelper = (node, min, max) => {
  if (!node) return true
  if ((min && node.value <= min) || (max && node.value > max)) return false
  if (
    !validateBSTHelper(node.left, min, node.value) ||
    !validateBSTHelper(node.right, node.value, max)
  )
    return false
  return true
}

const n1 = new TreeNode(1)
const n2 = new TreeNode(2)
n1.left = n2
const n3 = new TreeNode(3)
n1.right = n3
const n4 = new TreeNode(4)
n2.left = n4
const n5 = new TreeNode(5)
n2.right = n5
const n6 = new TreeNode(6)
const n7 = new TreeNode(7)
n3.left = n6
n3.right = n7
const n8 = new TreeNode(8)
const n9 = new TreeNode(9)
n4.left = n8
n4.right = n9
const n10 = new TreeNode(10)
const n11 = new TreeNode(11)
n5.left = n10
n5.right = n11
const n12 = new TreeNode(12)
const n13 = new TreeNode(13)
n6.left = n12
n6.right = n13
const n14 = new TreeNode(14)
const n15 = new TreeNode(15)
n7.left = n14
n7.right = n15

const t1 = new TreeNode(20)
const t2 = new TreeNode(10)
const t3 = new TreeNode(30)
t1.left = t2
t1.right = t3
const t4 = new TreeNode(5)
const t5 = new TreeNode(15)
t2.left = t4
t2.right = t5
const t6 = new TreeNode(3)
const t7 = new TreeNode(7)
t4.left = t6
t4.right = t7
const t8 = new TreeNode(17)
t5.right = t8

console.log(validateBST(n1)) // false
console.log(validateBST(t1)) // true
