const { SinglyLinkedList } = require('./singlyLinkedList')

class SinglyLinkedList_2_3 extends SinglyLinkedList {
  /* Deletes a node in the middle of a linked list
     O(n) time complexity */
  deleteMiddle(node) {
    const nextNode = node.next
    node.value = nextNode.value
    node.next = nextNode.next
  }
}

const sll = new SinglyLinkedList_2_3()
sll.addNode(1)
sll.addNode(2)
sll.addNode(4)
const node = sll.addNode(8)
sll.addNode(16)
sll.addNode(32)
sll.addNode(64)
sll.printList() // 64 -> 32 -> 16 -> 8 -> 4 -> 2 -> 1
sll.deleteMiddle(node)
sll.printList() // 64 -> 32 -> 16 -> 4 -> 2 -> 1
