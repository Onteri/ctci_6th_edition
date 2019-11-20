/* Creates a binary search tree with minimal height */
const createMinimalBST = arr => {
  return minimalBST(arr, 0, arr.length - 1)
}

/* helper */
const minimalBST = (arr, start, end) => {
  if (start > end) return null
  const mid = Math.floor((start + end) / 2)
  const node = new TreeNode(arr[mid])
  n.left = minimalBST(arr, start, mid - 1)
  n.right = minimalBST(arr, mid + 1, end)
  return node
}

const arr = [1, 4, 6, 8, 9, 12, 19, 21]
const root = createMinimalBST(arr)
preOrderTraversal(root)
/*
8 
4
1
6
12
9
19
21
*/
