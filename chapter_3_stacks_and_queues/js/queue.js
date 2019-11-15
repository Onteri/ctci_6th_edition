/* first in, first out */
class Queue {
  constructor() {
    this.queue = []
    this.length = 0
  }

  enqueue(value) {
    this.queue.push(value)
    this.length++
  }

  dequeue() {
    this.length--
    return this.queue.shift()
  }

  isEmpty() {
    return this.length == 0
  }

  peek() {
    return this.queue[0]
  }
}

module.exports = {
  Queue
}

const q = new Queue()
const arr = [4, 5, 2, 8, 1, 9, 6, 7, 3, 0]
for (let i of arr) q.enqueue(i)
console.log(q)
/*
Queue { queue: [ 4, 5, 2, 8, 1, 9, 6, 7, 3, 0 ], length: 10 }
*/
console.log(q.dequeue()) // 4
console.log(q)
/*
Queue { queue: [ 5, 2, 8, 1, 9, 6, 7, 3, 0 ], length: 9 } 
*/
console.log(q.peek()) // 5
