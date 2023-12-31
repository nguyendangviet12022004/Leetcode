 
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
class Solution:
    def mergeTrees(self, root1, root2):
        def merge(root1 , root2):
            if not root1 and not root2 :
                return None 
            elif not root1:
                return root2 
            elif not root2 :
                return root1
            else :
                root = TreeNode(root1.val + root2.val)
                root.left = merge(root1.left, root2.left)
                root.right = merge(root1.right, root2.right)
                return root 
        return merge(root1,root2)