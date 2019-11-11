SinglyLinkedList = __import__('singly_linked_list').SinglyLinkedList


class SinglyLinkedList_2_7(SinglyLinkedList):

    def intersection(self, other_list):
        """
        Finds if two linked lists intersect and returns
        where they first meet
        O(n) time and space complexity
        """
        difference = self.length - other_list.length
        if self.length > other_list.length:
            long = self
            short = other_list
        else:
            long = other_list
            short = self
        long = long.head
        short = short.head
        while difference:
            long = long.next
            difference -= difference
        print(long.value, short.value)
        while long:
            if short == long:
                return short
            long = long.next
            short = short.next
        return None


sll = SinglyLinkedList_2_7()
sll.add_to_front(1)
sll.add_to_front(2)
sll.add_to_front(4)
sll.add_to_front(8)
sll.add_to_front(16)
sll.add_to_front(32)
sll.print_linked_list()  # 1-> 2-> 4-> 8-> 16-> 32
