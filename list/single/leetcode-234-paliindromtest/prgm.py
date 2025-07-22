class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

class main:

    def returnReversedList(self, list):
        prev = None
        node = list
        while node:
            nxtNode = node.next
            node.next = prev
            prev = node
            node = nxtNode
        
        return prev

    def checkPalindrome(self, list):
        slow = fast = list
        while fast and fast.next:
            slow = slow.next
            fast = fast.next.next
        
        lista = list
        listmid = slow
        reversedMidList = self.returnReversedList(listmid)

        while reversedMidList:
            if reversedMidList.val != lista.val:
                print("not a palindrome\n")
                return
            reversedMidList = reversedMidList.next
            lista = lista.next
        
        return print("palindrome\n")


a = ListNode(2)
b = ListNode(3)
c = ListNode(2)
d = ListNode(2)

a.next = b
b.next = c
c.next = d
d.next = None

objectMaking = main()
objectMaking.checkPalindrome(a)

