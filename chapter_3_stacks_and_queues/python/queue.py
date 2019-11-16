# first in, first out
class Queue():
    def __init__(self):
        self.queue = []
        self.length = 0

    def enqueue(self, value):
        self.queue.append(value)
        self.length += 1

    def dequeue(self):
        self.length -= 1
        return self.queue.pop(0)

    def peek(self):
        return self.queue[0]

    def is_empty(self):
        return self.length == 0


if __name__ == 'main':
    q = Queue()
    for i in range(5):
        q.enqueue(i)
    print(q.queue)  # [0, 1, 2, 3, 4]
    print(q.dequeue())  # 0
    print(q.peek())  # 1
