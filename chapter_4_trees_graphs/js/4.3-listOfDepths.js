const { SinglyLinkedList } = require('./singlyLinkedList')
const { TreeNode } = require('./tree')

const createLevelLinkedList = root => {
  let result = []
  let current = new SinglyLinkedList()
  if (root) current.addNode(root)
  while (current.length) {
    result.push(current)
    let parents = current
    current = new SinglyLinkedList()
    tmp = parents.head
    /* loop through all nodes in parent */
    while (tmp) {
      if (tmp.left) current.addNode(tmp.left)
      if (tmp.right) current.addNode(tmp.right)
      tmp = tmp.next
    }
  }
  return result
}

const n1 = new TreeNode(1)
const n2 = new TreeNode(2)
const n3 = new TreeNode(3)
n1.left = n2
n1.right = n3
const n4 = new TreeNode(4)
const n5 = new TreeNode(5)
n2.left = n4
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

let res = createLevelLinkedList(n1)
for (let r of res) {
  r.printList()
}
/*
1
3 -> 2
5 -> 4 -> 7 -> 6
13 -> 12 -> 15 -> 14 -> 9 -> 8 -> 11 -> 10
*/
