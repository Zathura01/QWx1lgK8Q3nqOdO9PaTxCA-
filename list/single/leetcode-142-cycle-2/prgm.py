
class cycleDet:
    def __init__(self):
        self.hashmap = {}

    def CycleDetectin(self, head):
        i = 0
        while head:
            if head in self.hashmap:
                print(head, " ", head.val)
                return head
            else:
                self.hashmap[head] = i
            head = head.next
            i = i+1
    
class ListNode:
    def __init__(self, val=0, next = None):
        self.val = val
        self.next = next

a = ListNode(3)
b = ListNode(34)
c = ListNode(4)
d = ListNode(1)
a.next = b
b.next = c
c.next = d
d.next = c

check = cycleDet()
check.CycleDetectin(a)   
        


        