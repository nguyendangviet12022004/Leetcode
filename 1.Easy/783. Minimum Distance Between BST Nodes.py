class TreeNode:
    def __init__(self,val = 0 , left = None, right = None ) -> None:
        self.val = val 
        self.left = left 
        self.right = right 

class Solution:
    def minDiffInBST(self,root:TreeNode)-> int : 
        ans = 100000000
        def DFS(root: TreeNode) -> int:
            global ans 
            if root.left :
                ans = min(abs(root.val- root.left.val),ans)
                DFS(root.left)
            if root.right: 
                ans = min(abs(root.val-root.right.val),ans)
                DFS(root.right)
        
        DFS(root)
        return ans;