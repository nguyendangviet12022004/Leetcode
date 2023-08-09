class ListNode:
    def __init__(self,val = 0 , next = None) -> None:
        self.val = val
        self.next = next 

'''Solution: Using merge sort + tree skill to solve
Complexity: O(n)
'''


class Solution: 
    def mergeTwoSortedList(self,list1, list2 ):
        head = ListNode()
        ans = head 
        while list1 and list2:
            k1 = list1.val
            k2 = list2.val
            if k1 < k2 :
                ans.next = ListNode(k1)
                ans = ans.next
                list1 = list1.next
            else :
                ans.next = ListNode(k2)
                ans = ans.next
                list2 = list2.next
        while list1 :
            ans.next = ListNode(list1.val)
            ans = ans.next
            list1 = list1.next

        while list2 :
                    ans.next = ListNode(list2.val)
                    ans = ans.next
                    list2 = list2.next
        return head.next

