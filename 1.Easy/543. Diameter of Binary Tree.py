class TreeNode:
    def __init__(self,val = 0, left = None , right = None) -> None:
        self.val = val 
        self.left = left 
        self.right = right 
'''Solution: Using recursion particularly DFS'''

class Solution:
    def diameterOfBinaryTree(self, root: TreeNode) -> int:
        if not root:
            return 0
        global d 
        d = 0 
        def DFS(root):
            global d
            if not root:
                return 0 
            dl = DFS(root.left)
            dr = DFS(root.right)
            d = max(d,dl+dr)
            return 1 + max(dl,dr)

        DFS(root)
        return d