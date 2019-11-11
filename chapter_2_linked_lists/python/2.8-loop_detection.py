SinglyLinkedList = __import__('singly_linked_list').SinglyLinkedList


class SinglyLinkedList_2_8(SinglyLinkedList):

    def is_circular(self):
        """
        Determines if linked list is circular
        O(n) solution
        """
        hare = tortoise = self.head
        while hare and hare.next:
            hare = hare.next.next
            tortoise = tortoise.next
            if hare == tortoise:
                return True
        return False


sll = SinglyLinkedList_2_8()
sll.add_to_front(1)
sll.add_to_front(2)
sll.add_to_front(3)
n4 = sll.add_to_front(4)
sll.add_to_front(3)
sll.add_to_front(2)
sll.add_to_front(1)
sll.print_linked_list()  # 1-> 2-> 3-> 4-> 3-> 2-> 1
print(sll.is_circular())  # False

# making this circular
curr = sll.head
while curr.next:
    curr = curr.next
curr.next = n4

print(sll.is_circular())  # True
