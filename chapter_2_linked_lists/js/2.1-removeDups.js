const { SinglyLinkedList } = require("./singlyLinkedList")

class SinglyLinkedList_2_1 extends SinglyLinkedList {
  /**
   * Delete nodes with duplicate values in a linked list.
   * O(n) time complexity.
   */
  removeDups() {
    const set = new Set()
    let curr = this.head
    let index = 0
    while (curr) {
      const val = curr.value
      if (set.has(val)) {
        this.deleteNode(index)
      } else {
        set.add(val)
        index++
      }
      curr = curr.next
    }
  }
}

const sll = new SinglyLinkedList_2_1()
const arr = [1, 1, 2, 2, 4, 8, 16, 16]
for (let i of arr) sll.addNode(i)
sll.printList() // 16 -> 16 -> 8 -> 4 -> 2 -> 2 -> 1 -> 1
sll.removeDups()
sll.printList() // 16 -> 8 -> 4 -> 2 -> 1
