class ListNode:
    def __init__(self,val = 0 , next = None ) :
        self.val = val
        self.next = next

    
'''Solution: add all node into a list by the rule : if even id  : add first then ad node which has odd id 
Complexity: O(n)'''
class Solution: 
    def swapPairs(self,head):
        if not head or not head.next:
            return head 
        queue = []
        id = 1 
        pre = None 
        while head :
            if id & 1 :
                pre = head 
            else :
                queue.append(head)
                queue.append(pre)
                pre = None 
            head = head.next
            id += 1 
        if pre :
            queue.append(pre)
        head = queue[0]
        for i in range(1,len(queue)):
            queue[i-1].next = queue[i]
        head[-1].next = None 
        return head 

        
                
