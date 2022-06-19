from typing import List

class Node:
    def __init__(self,inputData: int) -> None:
        self.left = None
        self.data = inputData
        self.right = None

def preOrder(currNode):
    if(currNode==None):
        return
    print(currNode.data,end=" ")
    preOrder(currNode.left)
    preOrder(currNode.right)

def main():
    root = Node(10)
    root.left = Node(7)
    root.left.left = Node(6)
    root.left.left.left = Node(1)

    # left child
    root.left.right = Node(8)
    root.left.right.right = Node(9)

    # right child
    root.right = Node(11)
    root.right.right = Node(20)
    root.right.right.right = Node(22)
    root.right.right.left = Node(14)

    preOrder(root)
    print("")

if __name__ == "__main__":
	main()

'''
https://www.geeksforgeeks.org/tree-traversals-inorder-preorder-and-postorder/

https://www.youtube.com/watch?v=BHB0B1jFKQc&t=679s
Binary Tree Bootcamp: Full, Complete, & Perfect Trees. Preorder, Inorder, & Postorder Traversal.

https://www.hackerrank.com/challenges/tree-preorder-traversal/problem?isFullScreen=false
'''