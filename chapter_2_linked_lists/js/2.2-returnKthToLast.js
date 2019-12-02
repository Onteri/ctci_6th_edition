const { SinglyLinkedList, Node } = require("./singlyLinkedList")

class SinglyLinkedList_2_2 extends SinglyLinkedList {
  /**
   * Returns the kth element from last node.
   * O(n) time complexity.
   * @param   {number}  index
   * @returns {Node}
   */
  kthToLast(index) {
    if (index > this.length || index < 0) throw new Error("index out of range")
    let curr = this.head
    let kth = this.head
    while (index) {
      index--
      curr = curr.next
    }
    while (curr) {
      curr = curr.next
      kth = kth.next
    }
    return kth
  }
}

const sll = new SinglyLinkedList_2_2()
const arr = [1, 2, 4, 8, 16, 32, 64]
for (let i of arr) sll.addNode(i)
sll.printList() // 64 -> 32 -> 16 -> 8 -> 4 -> 2 -> 1

let node = sll.kthToLast(1)
console.log(node.value) // 1
node = sll.kthToLast(3)
console.log(node.value) // 4
node = sll.kthToLast(5)
console.log(node.value) // 16
