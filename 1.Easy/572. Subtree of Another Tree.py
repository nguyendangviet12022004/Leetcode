class TreeNode:
    def __init__(self, val = 0 , left = None , right = None) -> None:
        self.val = val 
        self.left = left 
        self.right = right 

class Solution:
    def isSubtree(self, root: TreeNode, subRoot: TreeNode)-> bool: 
        def compare(root:TreeNode,subRoot:TreeNode):
            if not root and not subRoot:
                return True
            if not root or not subRoot:
                return False
            if root.val == subRoot.val :
                return compare(root.left, subRoot.left) and compare(root.right, subRoot.right )
            
            else :
                return False
        
    
        def DFS(root):
            if compare(root,subRoot):
                return True
            else:
                return compare(root.left,subRoot) or compare(root.right,subRoot)
        
        return DFS(root)
            
root1 = TreeNode(1)
root1.left = TreeNode(2)
root1.right = TreeNode(3)

root2 = TreeNode(1)
root2.left = TreeNode(2)
root2.right = TreeNode(3)

print(Solution().isSubtree(root1,root2))