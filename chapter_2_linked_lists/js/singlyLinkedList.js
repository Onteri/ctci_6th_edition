/* A Singly Linked List Class */
class SinglyLinkedList {
  /* Constructor, instance attributes include head pointer
     and length */
  constructor() {
    this.head = null
    this.length = 0
  }

  /* Add a node to head of list */
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

  /* Deletes a node given the index */
  deleteNode(index) {
    /* delete head */
    let curr = this.head
    let prev
    if (index >= this.length || index < 0) throw new Error('index out of range')
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

  /* Print a linked list */
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

  /* Extends a linked list with input node */
  extend(node) {
    let curr = this.head
    while (curr.next) curr = curr.next
    curr.next = node
    while (node) {
      node = node.next
      this.length++
    }
  }
}

/* A Node class */
class Node {
  /* Constructor, instance attributes include value and
     next pointer */
  constructor(value) {
    this.value = value
    this.next = null
  }
}

module.exports = {
  SinglyLinkedList,
  Node
}
