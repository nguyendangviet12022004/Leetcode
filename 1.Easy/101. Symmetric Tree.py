class TreeNode:
    def __init__(self,val = 0,left = None ,right = None) -> None:
        self.val = val
        self.left = left
        self.right = right
    
'''Solution: Using recursion : node1.val = node2.val and node1.left = node2.right and node1.right = node2.left'''
class Solution:
    def isSymmetric(seft,root):
        def dfs(root1,root2):
            if not root1 and not root2 :
                return True
            if not root1 or not root2 : 
                return False 
            return root1.val == root2.val and dfs(root1.left,root2.right) and dfs(root1.right,root2.left)   
        return dfs(root.left,root.right)

