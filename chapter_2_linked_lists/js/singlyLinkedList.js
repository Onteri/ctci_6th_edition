class SinglyLinkedList {
  /* LinkedList constructor */
  constructor() {
    this.head = null
    this.length = 0
  }

  /* Adds a new node to the head of a singly linked list */
  addNode(value) {
    const node = new Node(value)
    if (!this.head) {
      this.head = node
    } else {
      node.next = this.head
      this.head = node
    }
    this.length++
    return node
  }

  /* Deletes a node at a given index */
  deleteNode(index) {
    /* delete head */
    let curr = this.head
    let prev
    if (index >= this.length || index < 0) throw new Error("index out of range")
    if (index === 0) {
      this.head = curr.next
    } else if (index === this.length - 1) {
      /* delete last node */
      while (curr.next) {
        prev = curr
        curr = curr.next
      }
      prev.next = null
    } else {
      while (index) {
        prev = curr
        index--
        curr = curr.next
      }
      prev.next = curr.next
    }
  }

  /* Prints all elements of a singly linked list */
  printList() {
    let curr = this.head
    let str = ""
    while (curr) {
      str += curr.value
      str += curr.next ? " -> " : ""
      curr = curr.next
    }
    console.log(str)
  }
}

class Node {
  /* Node constructor */
  constructor(value) {
    this.value = value
    this.next = null
  }
}

module.exports = {
  SinglyLinkedList,
  Node
}
