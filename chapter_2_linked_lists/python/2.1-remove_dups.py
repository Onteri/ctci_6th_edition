SinglyLinkedList = __import__('singly_linked_list').SinglyLinkedList


class SinglyLinkedList_2_1(SinglyLinkedList):

    def del_dups(self):
        """
        Delete nodes with duplicate values in a linked list
        O(n) time complexity
        """
        curr = self.head
        _set = set()
        index = 0
        while curr:
            if curr.value in _set:
                self.delete_node(index)
            else:
                _set.add(curr.value)
                index += 1
            curr = curr.next


sll = SinglyLinkedList_2_1()
sll.add_to_front(1)
sll.add_to_front(1)
sll.add_to_front(2)
sll.add_to_front(4)
sll.add_to_front(4)
sll.add_to_front(8)
sll.add_to_front(8)

sll.print_linked_list()  # 8-> 8-> 4-> 4-> 2-> 1-> 1
sll.del_dups()
sll.print_linked_list()  # 8-> 4-> 2-> 1
