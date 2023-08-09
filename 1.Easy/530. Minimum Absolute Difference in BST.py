class TreeNode:
    def __init__(self,val = 0, left = None, right = None) -> None:
        self.val = val 
        self.left = left 
        self.right = right
    
class Solution: 
    def getMinimumDifference(self, root : TreeNode) -> int :
        def push_node_in_array(root,array:list[int]):
            if not root: 
                return array
            array.append(root.val)
            array = push_node_in_array(root.left,array)
            array = push_node_in_array(root.right,array)

            return array
        arr = push_node_in_array(root,[])
        arr.sort()
        ans = 100001
        for i in range(len(arr)-1):
            ans = min(ans,arr[i+1] - arr[i])
        return ans
              
