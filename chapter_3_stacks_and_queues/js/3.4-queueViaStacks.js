const { Stack } = require("./stack")

/* first in, first out*/
class MyQueue {
  constructor() {
    this.newest = new Stack()
    this.oldest = new Stack()
  }

  size() {
    return this.newest.length + this.oldest.length
  }

  enqueue(value) {
    this.newest.push(value)
  }

  shiftStacks() {
    /* If oldest is empty, push everything from newest to oldest */
    if (this.oldest.isEmpty()) {
      while (!this.newest.isEmpty()) {
        this.oldest.push(this.newest.pop())
      }
    }
  }

  dequeue() {
    this.shiftStacks()
    return this.oldest.pop()
  }

  peek() {
    this.shiftStacks()
    return this.oldest.peek()
  }
}

const mq = new MyQueue()
const arr = [1, 2, 3, 4, 5]
for (let i of arr) mq.enqueue(i)
console.log(mq)
/*
MyQueue {
  newest: Stack { stack: [ 1, 2, 3, 4, 5 ], length: 5 },
  oldest: Stack { stack: [], length: 0 } }
*/
console.log(mq.dequeue()) // 1
console.log(mq)
/*
MyQueue {
  newest: Stack { stack: [], length: 0 },
  oldest: Stack { stack: [ 5, 4, 3, 2 ], length: 4 } }
*/
mq.enqueue(6)
console.log(mq)
/*
MyQueue {
  newest: Stack { stack: [ 6 ], length: 1 },
  oldest: Stack { stack: [ 5, 4, 3, 2 ], length: 4 } }
*/
console.log(mq.dequeue()) // 2
console.log(mq)
/*
MyQueue {
  newest: Stack { stack: [ 6 ], length: 1 },
  oldest: Stack { stack: [ 5, 4, 3 ], length: 3 } }
*/
console.log(mq.size()) // 4
console.log(mq.peek()) // 3
