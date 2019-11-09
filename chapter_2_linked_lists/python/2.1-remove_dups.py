class LinkedList:
  def __init__(self):
    self.head = None
    self.length = 0

  def add_to_end(self, node):
    if self.head is None:
      self.head = node
      self.length += 1
    else:
      curr = self.head
      while curr:
        prev = curr
        curr = curr.next
      prev.next = node
      self.length += 1

  def delete_node(self, index):
    curr = self.head
    if index == 0:
      self.head = curr.next
      return
    if index == self.length - 1:
      while curr.next:
        prev = curr
        curr = curr.next
      prev.next = None
      del(curr)
      return
    while index != 0:
      prev = curr
      curr = curr.next
      index -= 1
    prev.next = curr.next if curr else None
        
  def print_linked_list(self):
    curr = self.head
    while curr:
      print(curr.value)
      curr = curr.next

  def del_replica(self):
    curr = self.head
    repl = set()
    index = 0
    while curr:
      if curr.value in repl:
        self.delete_node(index)
        index -= 1
      else:
        repl.add(curr.value)
      index += 1
      curr = curr.next

  def print_kthelem(self, k):
    curr = self.head
    kth = self.head
    while k != 0:
      curr = curr.next
      k -= 1
    while curr.next:
      curr = curr.next
      kth = kth.next
    return(kth.value)


def del_middle(self)


class Node:
  def __init__(self, value):
    self.value = value
    self.next = None

new_ll = LinkedList()
print(new_ll)
new_ll.add_to_end(Node(1))
new_ll.add_to_end(Node(2))
new_ll.add_to_end(Node(4))
new_ll.add_to_end(Node(8))
new_ll.add_to_end(Node(16))
new_ll.add_to_end(Node(32))
new_ll.add_to_end(Node(64))
new_ll.add_to_end(Node(128))
new_ll.print_kthelem(6)
new_ll.print_linked_list()
