const { SinglyLinkedList, Node } = require("./singlyLinkedList")

class SinglyLinkedList_2_7 extends SinglyLinkedList {
  /**
   * Finds if two linked lists intersect and returns the node where they first
   * meet.
   * O(n) time and space complexity.
   * @param   {SinglyLinkedList_2_7}  otherList
   * @returns {(Node|null)}
   */
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
let n6 = sll2.addNode(6)
n6.next = n5
sll2.printList() // 6 -> 4 -> 5 -> 1 -> 3

console.log(sll.findIntersection(sll2)) // Node { value: 5, next: Node }

const sll3 = new SinglyLinkedList_2_7()
const arr = [3, 1, 5, 9, 7, 2, 8]
for (let i of arr) sll3.addNode(i)
sll3.printList() // 1 -> 2 -> 7 -> 9 -> 5 -> 1 -> 3
console.log(sll.findIntersection(sll3)) // null
