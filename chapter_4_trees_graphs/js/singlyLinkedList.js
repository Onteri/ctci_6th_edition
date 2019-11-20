class SinglyLinkedList {
  /* Singly linked list constructor for tree nodes  */
  constructor() {
    this.head = null
    this.length = 0
  }

  /* Adds a new node to the head of a singly linked list */
  addNode(node) {
    if (!this.head) {
      this.head = node
    } else {
      node.next = this.head
      this.head = node
    }
    this.length++
    return node
  }

  /* Prints all elements of a singly linked list */
  printList() {
    let curr = this.head
    let str = ''
    while (curr) {
      str += curr.value
      str += curr.next ? ' -> ' : ''
      curr = curr.next
    }
    console.log(str)
  }
}

module.exports = {
  SinglyLinkedList
}
