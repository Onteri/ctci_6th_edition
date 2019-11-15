const { Stack } = require("./stack")

class StackWithCapacity extends Stack {
  constructor(capacity) {
    super()
    this.capacity = capacity
  }

  push(value) {
    if (this.isFull()) throw new Error("stack is full")
    this.stack.push(value)
    this.length++
  }

  isFull() {
    return this.length === this.capacity
  }
}

swc = new StackWithCapacity(5)
swc.push(1)
swc.push(1)
swc.push(1)
swc.push(1)
swc.push(1)
// swc.push(1) // error
console.log(swc)
/*
StackWithCapacity { stack: [ 1, 1, 1, 1, 1 ], length: 5, capacity: 5 }
*/

class SetOfStacks {
  constructor(stackCapacity) {
    this.stacks = []
    this.stacksLength = 0
    this.stackCapacity = stackCapacity
  }

  push(value) {
    const last = this.getLastStack()
    if (last != null && !last.isFull()) {
      /* add to last stack */
      last.push(value)
    } else {
      /* create new stack */
      const newStack = new StackWithCapacity(this.stackCapacity)
      newStack.push(value)
      this.stacks.push(newStack)
      this.stacksLength++
    }
  }

  pop() {
    const last = this.getLastStack()
    if (last === null) throw new Error("empty stack of stacks")
    const value = last.pop()
    /* If stack is empty, remove it from stacks */
    if (last.length === 0) {
      this.stacks.pop()
      this.stacksLength--
    }
    return value
  }

  getLastStack() {
    if (this.stacksLength === 0) return null
    return this.stacks[this.stacksLength - 1]
  }
}

const sos = new SetOfStacks(3)
console.log(sos)
/*
SetOfStacks { stacks: [], stacksLength: 0, stackCapacity: 3 }
*/
const arr = [1, 2, 3, 4, 5, 6, 7]
for (let i of arr) sos.push(i)
console.log(sos)
/*
SetOfStacks {
  stacks:
   [ StackWithCapacity { stack: [Array], length: 3, capacity: 3 },
     StackWithCapacity { stack: [Array], length: 3, capacity: 3 },
     StackWithCapacity { stack: [Array], length: 3, capacity: 3 },
     StackWithCapacity { stack: [Array], length: 1, capacity: 3 } ],
  stacksLength: 4,
  stackCapacity: 3 }
*/
/* remove 4 items */
for (let i of Array(4)) sos.pop()
console.log(sos)
/*
SetOfStacks {
  stacks:
   [ StackWithCapacity { stack: [Array], length: 3, capacity: 3 } ],
  stacksLength: 1,
  stackCapacity: 3 }
*/
