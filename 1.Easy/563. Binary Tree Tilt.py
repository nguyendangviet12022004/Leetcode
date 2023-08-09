class ListNode:
    def __init__(self,val = 0 , left = None, right = None ) -> None:
        self.val = val 
        self.left = left 
        self.right = right 

'''Solution: Using DFS'''
class Solution: 
    def TreeTilt(self, root):
        self. ans = 0 
        def Sum(root):
            if not root:
                return 0 
            dl = Sum(root.left)
            dr = Sum(root.right)

            self.ans += abs(dl-dr)
            return root.val + dl + dr 
        Sum(root)
        return self.ans  