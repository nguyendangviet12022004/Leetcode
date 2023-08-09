import time 
class ListNode:
    def __init__(self,val = 0, next = None ) -> None:
        self.val = val
        self.next = next
'''Solution: Using pointer to reverse
Complexity:o(n)'''

class Solution:
    def reverseList(self, head) :
        if not head or not head.next :
            return head 
        tail = head.next
        pre = head 
        while tail:
            time.sleep(1)           
            copy = tail 
            tail = tail.next 
            copy.next = pre 
            pre = copy 
        head.next = None
        return pre 
    
k = ListNode(1)
k.next = ListNode(2)
k.next.next = ListNode(3)
k.next.next.next = ListNode(4)
k.next.next.next.next = ListNode(5)

Solution().reverseList(k)