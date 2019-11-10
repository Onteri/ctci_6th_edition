const { SinglyLinkedList } = require("./singlyLinkedList")

class SinglyLinkedList_2_6 extends SinglyLinkedList {
  /* Determines if a linked list is a palindrome
     O(n) time and space complexity */
  isPalindrome() {
    let hare = this.head
    let tortoise = this.head
    let stack = []
    /* set tortoise to be middle node */
    while (hare && hare.next) {
      hare = hare.next.next
      stack.push(tortoise.value)
      tortoise = tortoise.next
    }
    /* for odd-numbered lists */
    if (this.length & 1) tortoise = tortoise.next
    while (tortoise) {
      if (tortoise.value != stack.pop()) return false
      tortoise = tortoise.next
    }
    return true
  }
}

const sll = new SinglyLinkedList_2_6()
sll.addNode(1)
sll.addNode(2)
sll.addNode(3)
sll.addNode(4)
sll.addNode(3)
sll.addNode(2)
sll.addNode(1)
sll.printList() // 1 -> 2 -> 3 -> 4 -> 3 -> 2 -> 1
console.log(sll.isPalindrome()) // true

const sll2 = new SinglyLinkedList_2_6()
sll2.addNode(1)
sll2.addNode(2)
sll2.addNode(3)
sll2.addNode(3)
sll2.addNode(2)
sll2.addNode(1)
sll2.printList() // 1 -> 2 -> 3 -> 3 -> 2 -> 1
console.log(sll2.isPalindrome()) // true

const sll3 = new SinglyLinkedList_2_6()
sll3.addNode(1)
sll3.addNode(2)
sll3.addNode(4)
sll3.addNode(3)
sll3.addNode(2)
sll3.addNode(1)
sll3.printList() // 1 -> 2 -> 3 -> 4 -> 2 -> 1
console.log(sll3.isPalindrome()) // true
