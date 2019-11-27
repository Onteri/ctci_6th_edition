const { TreeNode } = require("./tree")

/* Returns the amount of paths in a binary tree that equal a target sum */
const countPathsWithSum = (root, targetSum) => {
  return cpwsHelper(root, targetSum, 0, {})
}

/* Helper */
const cpwsHelper = (node, targetSum, runningSum, pathCount) => {
  if (!node) return 0
  /* Count paths with sum ending at the current node */
  runningSum += node.value
  const sum = runningSum - targetSum
  let totalPaths = pathCount[sum] || 0
  /* If runningSum equals targetSum, then one additional path starts at root.
   * Add in this path. */
  if (runningSum == targetSum) {
    totalPaths++
  }

  /* Increment pathCount, recurse, then decrement pathCount */
  modifyHashTable(pathCount, runningSum, 1) // Increment pathCount
  totalPaths += cpwsHelper(node.left, targetSum, runningSum, pathCount)
  totalPaths += cpwsHelper(node.right, targetSum, runningSum, pathCount)
  modifyHashTable(pathCount, runningSum, -1) // Decrement pathCount
  return totalPaths
}

/* Modifies a key in a hash table */
const modifyHashTable = (hashTable, key, delta) => {
  const newCount = (hashTable[key] || 0) + delta
  if (!newCount)
    // Remove when zero to reduce space usage
    delete hashTable[key]
  else hashTable[key] = newCount
}

const n1 = new TreeNode(10)
const n2 = new TreeNode(5)
const n3 = new TreeNode(-3)
n1.left = n2
n1.right = n3
const n4 = new TreeNode(3)
const n5 = new TreeNode(1)
n2.left = n4
n2.right = n5
const n7 = new TreeNode(11)
n3.right = n7
const n8 = new TreeNode(3)
const n9 = new TreeNode(-2)
n4.left = n8
n4.right = n9
const n11 = new TreeNode(2)
n5.right = n11

console.log(countPathsWithSum(n1, 8)) // 3
