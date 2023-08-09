class TreeNode :
    def __init__(self,val,left,right) -> None:
        self.val = val
        self.left = left
        self.right = right 
    
'''Solution : Usign recursion to mark level of each node '''
class Solution : 
    def isBalanced(self,root): 
        def compare(tree):
            if tree == None : 
                return 1

            dl = compare(tree.left)
            if dl == 0 :
                return 0
            dr = compare(tree.right)
            if dr == 0 :
                return 0

            if abs(dr - dl) > 1 :
                return 0
            return max(dr,dl) + 1
        return compare(root) != 0 