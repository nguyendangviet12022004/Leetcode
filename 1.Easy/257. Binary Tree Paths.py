
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
class Solution:
    def binaryTreePaths(self, root: TreeNode) -> list[str]:
        global arr
        arr = []
        def DFS(s:str , root : TreeNode):
            global arr
            if not root : 
                return ""
            if(s != ""):
                s += '->'
            s += str(root.val)
            if not root.left and not root.right:
                arr.append(s)
            DFS(s,root.left)
            DFS(s,root.right)
        DFS("",root)
        return arr
