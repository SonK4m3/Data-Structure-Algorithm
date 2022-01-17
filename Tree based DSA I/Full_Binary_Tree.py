# checking if a binary tree is a full binary tree in Python

# creating a node
class Node:
    def __init__(self, item):
        self.item = item
        self.right = None
        self.left = None
    
#Checking full binary tree
def isFullTree(root):
    if root is None:
        return True
    
    if root.left and root.right:
        return True
    
    if root.left is not None and root.right is not None:
        return (isFullTree(root.left) and isFullTree(root.right))

    return False

root = Node(1)
root.right = Node(2)
root.left = Node(3)

root.left.left = Node(4)
root.left.right = Node(5)
root.left.right.left = Node(6)
root.left.right.right = Node(7)

if isFullTree(root):
    print("The tree is a full binary tree")
else:
    print("The tree is not a full binary tree")