SinglyLinkedList = __import__('singly_linked_list').SinglyLinkedList


class SinglyLinkedList_2_2(SinglyLinkedList):

    def kth_elem_from_last(self, k):
        """
        Returns the kth element from last node
        O(n) time complexity
        """
        if k < 0 or k >= self.length:
            raise IndexError
        curr = kth = self.head
        while k != 0:
            curr = curr.next
            k -= 1
        while curr:
            curr = curr.next
            kth = kth.next
        return kth


sll = SinglyLinkedList_2_2()
sll.add_to_front(1)
sll.add_to_front(2)
sll.add_to_front(4)
sll.add_to_front(8)
sll.add_to_front(16)

sll.print_linked_list()
node = sll.kth_elem_from_last(1)  # 1
print(node.value)
node = sll.kth_elem_from_last(3)  # 4
print(node.value)
node = sll.kth_elem_from_last(5)  # 16
print(node.value)
