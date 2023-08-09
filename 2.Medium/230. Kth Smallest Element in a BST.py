class TreeNode :
    def __init__(self,val = 0 , left = None, right = None ) :
        self.val = val
        self.left = left 
        self.right = right

'''Solution: Similar to convert a tree to a sorted arrray
Complexity: O(n)'''

class Solution:
    def kthSmallest(self, root: TreeNode, k: int) -> int:
        def convert(root:TreeNode):
            if not root : 
                return []
            ans = convert(root.left)
            ans.append(root.val)
            ans.extend(convert(root.right))
            return ans
        ans = convert(root)
        return ans[k-1]
