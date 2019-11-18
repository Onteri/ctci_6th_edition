const { Queue } = require("./queue")

class Animal {
  /* Animal constructor */
  constructor(name) {
    this.name = name
    this._order = 0
  }

  /* Order getter */
  get order() {
    return this._order
  }

  /* Order setter */
  set order(number) {
    this._order = number
  }

  /* Determines if this animal is than another */
  isOlderThan(animal) {
    return this.order < animal.order
  }
}

class Dog extends Animal {
  /* Dog constructor */
  constructor(name) {
    super(name)
  }
}

class Cat extends Animal {
  /* Cat constructor */
  constructor(name) {
    super(name)
  }
}

class AnimalQueue {
  /* Animal queue constructor */
  constructor() {
    this.cats = new Queue()
    this.dogs = new Queue()
    this.order = 0
  }

  /* Add an animal to correct queue */
  enqueue(animal) {
    /* Order is used as a sort of timestamp, so that we can compare
     * the insertion order of a dog to a cat */
    animal.order = this.order
    this.order++
    if (animal instanceof Dog) this.dogs.enqueue(animal)
    else if (animal instanceof Cat) this.cats.enqueue(animal)
  }

  /* Look at tops of dog and cat queues, and pops the queue
   * with the oldest value */
  dequeueAny() {
    if (this.cats.isEmpty()) return this.dequeueDogs()
    if (this.dogs.isEmpty()) return this.dequeueCats()
    return this.dogs.peek().isOlderThan(this.cats.peek())
      ? this.dequeueDogs()
      : this.dequeueCats()
  }

  /* Pops the oldest cat from cat queue */
  dequeueCats() {
    return this.cats.dequeue()
  }

  /* Pops the oldest dog from dog queue */
  dequeueDogs() {
    return this.dogs.dequeue()
  }
}

const aq = new AnimalQueue()
console.log(aq)
/*
AnimalQueue {
  cats: Queue { queue: [], length: 0 },
  dogs: Queue { queue: [], length: 0 },
  order: 0 }
*/
const smokey = new Cat("smokey")
const spot = new Dog("spot")
const garfield = new Cat("garfield")
const grumpy = new Cat("grumpy")
const matador = new Dog("matador")
aq.enqueue(smokey)
aq.enqueue(matador)
aq.enqueue(garfield)
aq.enqueue(grumpy)
aq.enqueue(spot)
console.log(aq)
/*
AnimalQueue {
  cats: Queue { queue: [ [Cat], [Cat], [Cat] ], length: 3 },
  dogs: Queue { queue: [ [Dog], [Dog] ], length: 2 },
  order: 5 }
*/
console.log(aq.dequeueAny()) // Cat { name: 'smokey', _order: 0 }
console.log(aq.dequeueCats()) // Cat { name: 'garfield', _order: 2 }
console.log(aq.dequeueDogs()) // Dog { name: 'matador', _order: 1 }
console.log(aq.dequeueDogs()) // Dog { name: 'spot', _order: 4 }
console.log(aq.dequeueAny()) // Cat { name: 'grumpy', _order: 3 }
