const { SinglyLinkedList } = require("./singlyLinkedList")

class SinglyLinkedList_2_8 extends SinglyLinkedList {
  /**
   * Determines if linked list is circular.
   * O(n) solution.
   * @returns   {boolean}
   */
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
let s3 = sll.addNode(3)
sll.addNode(1)
sll.addNode(5)
sll.addNode(9)
sll.addNode(7)
let s2 = sll.addNode(2)
sll.addNode(8)
sll.printList() // 8 -> 2 -> 7 -> 9 -> 5 -> 1 -> 3
console.log(sll.isCircular()) // false

/* Making this circular. */
s3.next = s2
console.log(sll.isCircular()) // true
