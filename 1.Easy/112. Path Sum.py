class ListNode:
    def __init__(self,val = 0 , left = None, right = None) -> None:
        self.val = val 
        self.left = left 
        self.right = right 

class Solution:
    def hasPathSum(self, root :ListNode , targetSum : int ) -> bool :
        def check(root, targetSum):
            if not root:
                return False
            if not root.left and not root.right and root.val == targetSum:
                return True 
            return check(root.lef,targetSum-root.val) or check(root.right , targetSum- root.val )
        return check(root,targetSum)
        
