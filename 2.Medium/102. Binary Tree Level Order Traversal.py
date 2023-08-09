
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
class Solution:
    def levelOrder(self, root) :
        if not root :
            return []
        arr = []
        que = [root]
        while(len(que) != 0 ):
            l = len(que)
            add  = []
            for i in range(l):
                add.append(que[i].val)
                if (que[i].left) :
                    que.append(que[i].left)
                if (que[i].right):
                    que.append(que[i].right)
            arr.append(add)
            for i in range(l):
                que.pop(0)
        return arr