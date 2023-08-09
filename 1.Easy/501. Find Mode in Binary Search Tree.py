'''Solution: Using DFS 
Complexity: O(n)'''
class TreeNode:
    def __init__(self,val= 0, left =None , right = None ) -> None:
        self.val = val 
        self.left =left
        self.right = right 

class Solution:
    def findMode(self, root: TreeNode) -> list[int]:
        count = dict()
        def DFS (root):
            if root :
                if root.val not in count.keys():
                    count.update({root.val:1})
                else :
                    count[root.val] += 1
                DFS(root.left)
                DFS(root.right)
        DFS(root)
        count = sorted(count.items(),reverse=True,key = lambda x : x[1])
        kmax = count[0][1]
        ans = []
        id = 0 
        while id < len(count) and count[id] == kmax:
            ans.append(count[id])
            id += 1
        return ans 

num = int(input())

ans = ""
while num:
    ans = str(num % 7) + ans
    num //= 7
print( ans)