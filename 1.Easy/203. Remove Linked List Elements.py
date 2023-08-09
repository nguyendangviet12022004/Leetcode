class ListNode:
    def __init__(self, val = 0 , next = None) -> None:
        self.val = val 
        self.next = next

'''Solution: using pointer to check if node.val == val (remember there are some case which first element has val == target)
Complexity: O(n)'''
class Solution:
    def removeElements(self, head : ListNode , val : int)-> ListNode:
        ans = head 
        while ans  :
            if ans.val == val :
                ans = ans.next
            else:
                break  
        pre = ans 
        head = ans 
        while head :
            if head.val == val :
                pre.next = head.next 
            else :
                pre = head 
            head = head.next 
        return ans