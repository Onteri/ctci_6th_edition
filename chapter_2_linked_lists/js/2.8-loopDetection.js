const { SinglyLinkedList } = require('./singlyLinkedList')

class SinglyLinkedList_2_8 extends SinglyLinkedList {
  /* Determines if linked list is circular
     O(n) solution */
  isCircular() {
    let hare = this.head
    let tortoise = this.head
    while (hare && hare.next) {
      hare = hare.next.next
      tortoise = tortoise.next
      if (hare === tortoise) return true
    }
    return false
  }
}

const sll = new SinglyLinkedList_2_8()
sll.addNode(3)
sll.addNode(1)
let n5 = sll.addNode(5)
sll.addNode(9)
sll.addNode(7)
sll.addNode(2)
sll.addNode(8)
sll.printList() // 8 -> 2 -> 7 -> 9 -> 5 -> 1 -> 3
console.log(sll.isCircular()) // false

/* making this circular */
let curr = sll.head
while (curr.next) curr = curr.next
curr.next = n5

console.log(sll.isCircular()) // true
