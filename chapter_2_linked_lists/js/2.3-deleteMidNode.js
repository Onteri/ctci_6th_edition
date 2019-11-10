const { SinglyLinkedList } = require('./singlyLinkedList')

class SinglyLinkedList_2_3 extends SinglyLinkedList {
  /* Returns the kth element from last node
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
sll.printList()
sll.deleteMiddle(node)
sll.printList()
