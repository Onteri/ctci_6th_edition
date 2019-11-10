const { SinglyLinkedList } = require('./singlyLinkedList')

class SinglyLinkedList_2_1 extends SinglyLinkedList {
  /* Delete nodes with duplicate values in a linked list
     O(n) time complexity */
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
sll.addNode(1)
sll.addNode(1)
sll.addNode(2)
sll.addNode(2)
sll.addNode(4)
sll.addNode(8)
sll.addNode(16)
sll.addNode(16)
sll.printList()
sll.removeDups()
sll.printList()
