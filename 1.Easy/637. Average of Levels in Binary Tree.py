class TreeNode:
    def __init__(self,val = 0, left = None, right = None ) -> None:
        self.val = val 
        self.left = left
        self.right = right 
'''Solution: Using BFS '''

class Solution:
    def averageOfLevels(self, root: TreeNode) -> list[int]:
        if not root:
            return []
        queue = [root]
        ans = []
        while len(queue) != 0 :
            add = []
            l = len(queue)
            s = 0 
            for i in range(l):
                s += queue[i].val 
                if queue[i].left :
                    add.append(queue[i].left)
                if queue[i].right :
                    add.append(queue[i].right)
            queue.clear()
            queue = add.copy()
            ans.append(s / l)
        return ans 