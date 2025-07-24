class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

class DeleteMiddle:
    def delMid(self, head):
        if head is None or head.next is None:
            return None
        
        slow = fast = head
        prev = None
        while fast and fast.next:
            slow = slow.next
            fast = fast.next.next
            if prev is None:
                prev = head
            else:
                prev = prev.next
        next = slow.next
        prev.next = next
        return head

a = ListNode(3)
b = ListNode(5)
c = ListNode(6)
d = ListNode(2)
e = ListNode(2)

a.next = b
b.next = c
c.next = d
d.next = e
e.next = None

objt = DeleteMiddle()
f = objt.delMid(a)
while f:
    print(f.val)
    f = f.next
