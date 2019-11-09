class SinglyLinkedList:
    """A Singly Linked List Class"""

    def __init__(self):
        """
        Constructor, instance attributes include head pointer
        and length
        """
        self.head = None
        self.length = 0

    def add_to_front(self, value):
        """
        Add a node to head of list
        """
        node = Node(value)
        if self.head is None:
            self.head = node
        else:
            node.next = self.head
            self.head = node
        self.length += 1
        return node

    def delete_node(self, index):
        """
        Deletes a node given the index
        """
        curr = self.head
        # delete head
        if index == 0:
            self.head = curr.next
            del(curr)
            return
        # delete last node
        if index == self.length - 1:
            while curr.next:
                prev = curr
                curr = curr.next
            prev.next = None
            del(curr)
            return
        while index != 0 and curr:
            prev = curr
            curr = curr.next
            index -= 1
        if not curr:
            raise IndexError
        prev.next = curr.next
        del(curr)

    def print_linked_list(self):
        """
        Print a linked list
        """
        curr = self.head
        while curr:
            print(curr.value, end="-> " if curr.next else "\n")
            curr = curr.next


class Node:
    """A Node class"""

    def __init__(self, value):
        """
        Constructor, instance attributes include value and 
        next pointer
        """
        self.value = value
        self.next = None
