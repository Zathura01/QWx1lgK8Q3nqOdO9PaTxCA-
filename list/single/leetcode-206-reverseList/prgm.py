class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

class Main:
    def reverseList(self, head):
        node = head
        prev = None
        while node:
            nextNode = node.next
            node.next = prev
            prev = node
            node = nextNode
        return prev

# Build the linked list: 2 → 3 → 4 → 5
a = ListNode(2)
b = ListNode(3)
c = ListNode(4)
d = ListNode(5)
a.next = b
b.next = c
c.next = d

# Reverse it
main_obj = Main()
reversed_head = main_obj.reverseList(a)

# Print reversed list: 5 → 4 → 3 → 2
node = reversed_head
while node:
    print(node.val)
    node = node.next
