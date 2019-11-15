Stack = __import__('stack').Stack


class StackWithMin(Stack):
    def __init__(self):
        super().__init__()
        # new stack with minimums
        self.s2 = Stack()

    def push(self, value):
        if value < self.min():
            self.s2.push(value)
        super().push(value)

    def pop(self):
        # If min is getting popped, remove from second list also
        tmp = super().pop()
        if tmp == self.min():
            self.s2.pop()
        return tmp

    def min(self):
        if self.s2.is_empty():
            return float('inf')
        return self.s2.peek()


if __name__ == 'main':
    swm = StackWithMin()
    print(swm.__dict__)
    # {'stack': [], 'length': 0, 's2': <stack.Stack objek object at 0x7f6a0681a390>}
    for i in [4, -1, 2, 6, 2, -5]:
        swm.push(i)
    print(swm.min())  # -5
    print(swm.stack)  # [4, -1, 2, 6, 2, -5]
    print(swm.s2.stack)  # [4, -1, -5]
    print(swm.pop())  # -5
    print(swm.stack)  # [4, -1, 2, 6, 2]
    print(swm.s2.stack)  # [4, -1]
