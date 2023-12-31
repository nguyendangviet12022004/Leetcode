class TreeNode:
    def __init__(self,val = 0 , left = None, right = None ) -> None:
        self.val = val 
        self.left = left 
        self.right = right 

'''Solution: Using recursion 
Complexity: O(n)'''
class Solution:
    def isSameTree(self, p : TreeNode, q : TreeNode) -> bool : 
        def compare(p,q):
            if not p and not q :
                return True 
            if (not p and q) or (p and not q):
                return False 
            if p.val != q.val :
                return False 
            return compare(p.left,q.left) and compare(p.right,q.right)
        return compare(p,q)
