const { SinglyLinkedList } = require('./singlyLinkedList')

class SinglyLinkedList_2_4 extends SinglyLinkedList {
  /* Partitions a linked list according to a number
     All values lower than number will go on the left and 
     all values higher and equal will go on the right
     This solution is unstable, but performs at
     O(n) time complexity */
  partition(number) {
    let head = this.head
    let tail = this.head
    let curr = this.head
    while (curr) {
      let next_node = curr.next
      if (curr.value < number) {
        curr.next = head
        head = curr
      } else {
        tail.next = curr
        tail = curr
      }
      curr = next_node
    }
    tail.next = null
    this.head = head
  }
}

const sll = new SinglyLinkedList_2_4()
sll.addNode(10)
sll.addNode(30)
sll.addNode(11)
sll.addNode(31)
sll.addNode(12)
sll.addNode(33)
sll.addNode(13)
sll.printList() // 13 -> 33 -> 12 -> 31 -> 11 -> 30 -> 10
sll.partition(20)
sll.printList() // 10 -> 11 -> 12 -> 13 -> 33 -> 31 -> 30
