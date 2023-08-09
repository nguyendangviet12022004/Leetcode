class TreeNode:
    def __init__(self,val = 0 , left = None, right = None) -> None:
        self.val = val 
        self.left = left 
        self.right = right

def insert(node: TreeNode , data : int):
    if not node  :
        return TreeNode(data)
    else :
        if data > node.val :
            node.right  = insert(node.right, data)
        else :
            node.left = insert(node.left, data) 
        return node 

def Preoder(node: TreeNode):
    if node :
        print(node.val)
        Preoder(node.left)
        Preoder(node.right)

def Inorder(node: TreeNode):
    if node:
        Inorder(node.left)
        print(node.val)
        Inorder(node.right)

def Postorder(node: TreeNode):
    if node:
        Postorder(node.left)
        Postorder(node.right)
        print(node.val)


n = int(input())
node = None 

for i in range(0,n):
    x = int(input())
    node = insert(node,x)

Inorder(node)