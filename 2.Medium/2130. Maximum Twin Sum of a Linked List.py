class ListNode:
    def __init__(self,val=0,next= None) -> None:
        self.val= val
        self.next = next
    def push(self,val):
        while self.next:
            self = self.next
        self.next = ListNode(val)
    def print(self):
        while self:
            print(self.val,end=" ")
            self = self.next
        print()

'''Solution: put all node into an array and sovle
Complexity: O(n)'''
class Solution:
    def pairSum(self,head) :
        arr = []
        while head :
            arr.append(head.val)
            head = head.next
        n = len(arr)
        sum = arr[0] + arr[-1]
        for i in range(1,n//2):
            sum = max(sum,arr[i] + arr[n-1-i])
        return sum

head = ListNode()
for x in [5,4,2,1]:
    head.push(x)

head.print()
print(Solution().pairSum(head))