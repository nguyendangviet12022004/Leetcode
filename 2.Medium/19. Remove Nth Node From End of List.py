class ListNode:
    def __init__(self,val = 0 , next = None ) -> None:
        self.val = val
        self.next = next
    
'''Solution: count the number of node in list then delete (n-k)th element '''

class Solution:
    def removeNthFromEnd(self, head , n: int):
        count = 0
        copy = head 
        while copy :
            count +=1 
            copy = copy.next 

        index = count - n 
        if index == 0 :
            return head.next
        copy = head 
        while index-1:
            copy = copy.next 
            index -=1 
        copy.next = copy.next.next 
        return head 
             
            
k = ListNode(1)
k.next = ListNode(2)
k.next.next = ListNode(3)
k.next.next.next = ListNode(4)
k.next.next.next.next = ListNode(5)

Solution().removeNthFromEnd(k,3)