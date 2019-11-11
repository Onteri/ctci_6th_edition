SinglyLinkedList = __import__('singly_linked_list').SinglyLinkedList
Node = __import__('singly_linked_list').Node


class SinglyLinkedList_2_5(SinglyLinkedList):

    @staticmethod
    def sum_list(first_node, second_node, carry=0):
        """
        Adds the values of two linked lists by creating a new list
        O(a + b) solution, a and b being lengths of respective lists
        """
        if not first_node and not second_node and not carry:
            return None
        new_node = Node(0)
        value = carry
        if first_node:
            value += first_node.value
        if second_node:
            value += second_node.value
        new_node.value = value % 10
        if not first_node or not first_node.next:
            f = None
        else:
            f = first_node.next
        if not second_node or not second_node.next:
            s = None
        else:
            s = second_node.next
        if value >= 10:
            v = 1
        else:
            v = 0
        new_node.next = SinglyLinkedList_2_5.sum_list(f, s, v)
        return new_node


sll = SinglyLinkedList_2_5()
sll.add_to_front(6)
sll.add_to_front(1)
sll.add_to_front(7)
sll.print_linked_list()  # 1 -> 7 -> 6

sll2 = SinglyLinkedList_2_5()
sll2.add_to_front(2)
sll2.add_to_front(9)
sll2.add_to_front(5)
sll2.print_linked_list()  # 5 -> 9 -> 2

new_head = SinglyLinkedList_2_5.sum_list(sll.head, sll2.head)
sll3 = SinglyLinkedList_2_5()
sll3.head = new_head
sll3.print_linked_list()  # 2 -> 1 -> 9

sll4 = SinglyLinkedList_2_5()
sll4.add_to_front(9)
sll4.add_to_front(9)
sll4.add_to_front(9)
sll4.print_linked_list()  # 9 -> 9 -> 9

sll5 = SinglyLinkedList_2_5()
sll5.add_to_front(1)
sll5.print_linked_list()  # 1

new_head = SinglyLinkedList_2_5.sum_list(sll4.head, sll5.head)
sll6 = SinglyLinkedList_2_5()
sll6.head = new_head
sll6.print_linked_list()  # 0 -> 0 -> 0 -> 1
