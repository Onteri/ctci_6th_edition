/* first in, last out */
class Stack {
  constructor() {
    this.stack = []
    this.length = 0
  }

  push(value) {
    this.stack.push(value)
    this.length++
  }

  pop() {
    this.length--
    return this.stack.pop()
  }

  isEmpty() {
    return this.length === 0
  }

  peek() {
    return this.stack[this.length - 1]
  }
}

module.exports = {
  Stack
}

const st = new Stack()
console.log(st) // Stack { stack: [], length: 0 }
st.push(1)
st.push(2)
st.push(4)
console.log(st.peek()) // 4
st.pop()
console.log(st) // Stack { stack: [ 1, 2 ], length: 2 }
