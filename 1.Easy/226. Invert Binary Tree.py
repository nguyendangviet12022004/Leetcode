class TreeNode:
    def __init__(self,val = 0, left = None, right = None) -> None:
        self.val = val 
        self.right = right 
        self.left =left

class Solution:
    def invertTree(self,root: TreeNode) -> TreeNode:
        def invert(root):
            if not root:
                return ; 
            else :
                dl = root.left 
                dr = root.right 

                root.right = dl
                root.left = dr

                invert(root.left)
                invert(root.right)
        invert(root)
        return root