class Node:
    def __init__(self, data):
        self.data = data
        self.left = None
        self.right = None

class BinarySearchTree:
    def __init__(self):
        self.root = None
    
    def insert(self, data):
        if self.root is None:
            self.rooot = Node(data)
        else:
            newNode = Node(data)
            curr = self.root
            prev = None
            while curr is not None:
                prev = curr
                if data == curr.data:
                    print("Duplicate values are not allowed in BST")
                    return
                if data < curr.data:
                    curr = curr.left
                else:
                    curr = curr.right
            if data < prev.data:
                prev.left = newNode
            else:
                prev.right = newNode

newNode = Node(0)