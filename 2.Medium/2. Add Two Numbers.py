class ListNode:
    def __init__(self,value = 0, next = None) -> None:
        self.value = value
        self.next = next

'''Solution: just like you plus 2 int , but using tree '''
class Solution:
    def addTwoNumbers(self, l1,l2):
        carry = 0
        ans = ListNode()
        check = ans
        while l1 != None or l2 != None or carry != 0:
            k1 = l1.value if l1 else 0
            k2 = l2.value if l2  else 0
            k = k1 + k2 + carry

            carry = k // 10 
            check.next = ListNode(k % 10 )
            check = check.next 

            l1 = l1.next if l1 else None
            l2 = l2.next if l2 else None 

        return ans.next