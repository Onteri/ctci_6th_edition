Stack = __import__('stack').Stack

# first in, first out


class MyQueue():
    def __init__(self):
        self.newest = Stack()
        self.oldest = Stack()

    def size(self):
        return self.newest.length + self.oldest.length

    def enqueue(self, value):
        self.newest.push(value)

    def dequeue(self):
        self.shift_stacks()
        return self.oldest.pop()

    def peek(self):
        self.shift_stacks()
        return self.oldest.peek()

    def shift_stacks(self):
        # If oldest is empty, push everything from newest to oldest
        if self.oldest.is_empty():
            while not self.newest.is_empty():
                self.oldest.push(self.newest.pop())


if __name__ == "main":
    q = MyQueue()
    for i in range(10):
        q.enqueue(i)
    print(q.newest.stack, q.oldest.stack)
    # [0, 1, 2, 3, 4, 5, 6, 7, 8, 9] []
    print(q.dequeue())  # 0
    print(q.newest.stack, q.oldest.stack)
    # [] [9, 8, 7, 6, 5, 4, 3, 2, 1]
    print(q.peek())  # 1
    print(q.size())  # 9
