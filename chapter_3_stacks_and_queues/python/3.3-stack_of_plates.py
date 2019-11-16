Stack = __import__('stack').Stack


class StackWithCapacity(Stack):
    def __init__(self, capacity=5):
        super().__init__()
        self.capacity = capacity

    def push(self, value):
        if self.is_full():
            raise Exception('stack is full')
        super().push(value)

    def is_full(self):
        return self.length == self.capacity


class SetOfStacks:
    def __init__(self):
        self.stacks = []
        self.length = 0

    def push(self, value):
        last = self.get_last_stack()
        if last == None or last.is_full():
            # create new stack
            new_stack = StackWithCapacity()
            new_stack.push(value)
            self.stacks.append(new_stack)
            self.length += 1
        else:
            # add to last stack
            last.push(value)

    def pop(self):
        last = self.get_last_stack()
        if last == None:
            raise Exception('stacks are empty')
        value = last.pop()
        if last.is_empty():
            # If stack is empty, remove it from stacks
            self.stacks.pop()
            self.length -= 1
        return value

    def get_last_stack(self):
        if self.length == 0:
            return None
        return self.stacks[self.length - 1]


if __name__ == "main":
    swc = StackWithCapacity(5)
    for i in range(5):
        swc.push(i)
    print(swc.__dict__)
    # {'stack': [0, 1, 2, 3, 4], 'length': 5, 'capacity': 5}': 5, 'capacity': 5}

    sos = SetOfStacks()
    for i in range(11):
        sos.push(i)
    print([x.stack for x in sos.stacks])
    # [[0, 1, 2, 3, 4], [5, 6, 7, 8, 9], [10]] [10]]
    print(sos.pop())  # 10
    print(sos.pop())  # 9
    print([x.stack for x in sos.stacks])
    # [[0, 1, 2, 3, 4], [5, 6, 7, 8]]
