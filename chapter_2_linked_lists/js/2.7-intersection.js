const { SinglyLinkedList } = require("./singlyLinkedList")

class SinglyLinkedList_2_7 extends SinglyLinkedList {
  extend(node) {
    let curr = this.head
    while (curr.next) curr = curr.next
    curr.next = node
    while (node) {
      node = node.next
      this.length++
    }
  }

  /* Finds if two linked lists intersect and 
     where they first meet
     O(n) time and space complexity */
  findIntersection(otherList) {
    const longer = this.length > otherList.length ? this : otherList
    const shorter = this.length <= otherList.length ? this : otherList
    let difference = longer.length - shorter.length
    let longerStart = longer.head
    let shorterStart = shorter.head
    while (difference) {
      longerStart = longerStart.next
      difference--
    }
    while (longerStart) {
      if (longerStart == shorterStart) {
        return longerStart
      }
      longerStart = longerStart.next
      shorterStart = shorterStart.next
    }
    return null
  }
}

const sll = new SinglyLinkedList_2_7()
sll.addNode(3)
sll.addNode(1)
let n5 = sll.addNode(5)
sll.addNode(9)
sll.addNode(7)
sll.addNode(2)
sll.addNode(8)
sll.printList() // 1 -> 2 -> 7 -> 9 -> 5 -> 1 -> 3

const sll2 = new SinglyLinkedList_2_7()
sll2.addNode(4)
sll2.addNode(6)
sll2.extend(n5)
sll2.printList() // 6 -> 4 -> 5 -> 1 -> 3

console.log(sll.findIntersection(sll2)) // Node { value: 5, next: Node }

const sll3 = new SinglyLinkedList_2_7()
sll3.addNode(3)
sll3.addNode(1)
sll3.addNode(5)
sll3.addNode(9)
sll3.addNode(7)
sll3.addNode(2)
sll3.addNode(8)
sll3.printList() // 1 -> 2 -> 7 -> 9 -> 5 -> 1 -> 3
console.log(sll.findIntersection(sll3)) // null
