const { TreeNode } = require('./tree')

const checkBalanced = root => {
  return checkHeight(root) != Number.MIN_VALUE
}

const checkHeight = root => {
  if (!root) return -1
  let leftHeight = checkHeight(root.left)
  if (leftHeight === Number.MIN_VALUE) return Number.MIN_VALUE
  let rightHeight = checkHeight(root.right)
  if (rightHeight === Number.MIN_VALUE) return Number.MIN_VALUE
  let difference = leftHeight - rightHeight
  if (Math.abs(difference) > 1) return Number.MIN_VALUE
  else return Math.max(leftHeight, rightHeight) + 1
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
n3.left = n6
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

console.log(checkBalanced(n1)) // false
