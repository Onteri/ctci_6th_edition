const { SinglyLinkedList } = require("./singlyLinkedList")

class SinglyLinkedList_2_6 extends SinglyLinkedList {
  /* Determines if a linked list is a palindrome
   * O(n) time and space complexity */
  isPalindrome() {
    let hare = this.head
    let tortoise = this.head
    let stack = []
    /* navigate to middle node */
    while (hare && hare.next) {
      hare = hare.next.next
      stack.push(tortoise.value)
      tortoise = tortoise.next
    }
    /* for odd-lengthedlists */
    if (this.length & 1) tortoise = tortoise.next
    while (tortoise) {
      if (tortoise.value != stack.pop()) return false
      tortoise = tortoise.next
    }
    return true
  }
}

const sll = new SinglyLinkedList_2_6()
const arr = [1, 2, 3, 4, 3, 2, 1]
for (let i of arr) sll.addNode(i)
sll.printList() // 1 -> 2 -> 3 -> 4 -> 3 -> 2 -> 1
console.log(sll.isPalindrome()) // true

const sll2 = new SinglyLinkedList_2_6()
arr = [1, 2, 3, 3, 2, 1]
for (let i of arr) sll2.addNode(i)
sll2.printList() // 1 -> 2 -> 3 -> 3 -> 2 -> 1
console.log(sll2.isPalindrome()) // true

const sll3 = new SinglyLinkedList_2_6()
arr = [1, 2, 4, 3, 2, 1]
for (let i of arr) sll3.addNode(i)
sll3.printList() // 1 -> 2 -> 3 -> 4 -> 2 -> 1
console.log(sll3.isPalindrome()) // true
