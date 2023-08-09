# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
class Solution:
    def tree2str(self, root: TreeNode) -> str:
        def DFS(root):
            if not root:
                return ''
            result = str(root.val)
            if root.left:
                result += '(' + DFS(root.left) + ')'
            if root.right :
                if not root.left :
                    result += '()'
                result += '(' + DFS(root.right) + ')'
            
            return result

        return DFS(root)