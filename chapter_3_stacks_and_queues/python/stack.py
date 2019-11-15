class Stack:
    def __init__(self):
        self.stack = []
        self.length = 0

    def push(self, value):
        self.stack.append(value)
        self.length += 1

    def pop(self):
        return self.stack.pop()

    def peek(self):
        return self.stack[self.length - 1]

    def is_empty(self):
        return self.length == 0


if __name__ == "main":
    s = Stack()
    for i in [1, 2, 3, 4, 5]:
        s.push(i)
    print(s.stack)  # [1, 2, 3, 4, 5]
    print(s.pop())  # 5
    print(s.peek())  # 4
    print(s.stack)  # [1, 2, 3, 4]
