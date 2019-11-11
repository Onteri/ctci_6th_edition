const { SinglyLinkedList, Node } = require('./singlyLinkedList')

class SinglyLinkedList_2_5 extends SinglyLinkedList {
  /* Adds the values of two linked lists by creating a new list 
     O(a + b) solution, a and b being lengths of respective lists */
  static sumList(firstNode, secondNode, carry = 0) {
    if (!firstNode && !secondNode && !carry) {
      return null
    }
    const currentNode = new Node()
    let sum = carry
    if (firstNode) sum += firstNode.value
    if (secondNode) sum += secondNode.value
    currentNode.value = sum % 10
    if (firstNode || secondNode) {
      const nextNode = this.sumList(
        firstNode ? firstNode.next : null,
        secondNode ? secondNode.next : null,
        sum >= 10 ? 1 : 0
      )
      currentNode.next = nextNode
    }
    return currentNode
  }
}

const sll = new SinglyLinkedList_2_5()
sll.addNode(6)
sll.addNode(1)
sll.addNode(7)
sll.printList() // 7 -> 1 -> 6

const sll2 = new SinglyLinkedList_2_5()
sll2.addNode(2)
sll2.addNode(9)
sll2.addNode(5)
sll2.printList() // 5 -> 9 -> 2

const head = SinglyLinkedList_2_5.sumList(sll.head, sll2.head)
const sll3 = new SinglyLinkedList_2_5()
sll3.head = head
sll3.printList() // 2 -> 1 -> 9

const sll4 = new SinglyLinkedList_2_5()
sll4.addNode(9)
sll4.addNode(9)
sll4.addNode(9)
sll4.printList() // 9 + 9 + 9

const sll5 = new SinglyLinkedList_2_5()
sll5.addNode(1)
sll5.printList() // 1

const head2 = SinglyLinkedList_2_5.sumList(sll4.head, sll5.head)
const sll6 = new SinglyLinkedList_2_5()
sll6.head = head2
sll6.printList() // 0 -> 0 -> 0 -> 1
