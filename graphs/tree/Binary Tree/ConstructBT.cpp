#include <bits/stdc++.h>
using namespace std;

class Node{
public:
    Node *left;
    int data;
    Node *right;

    // This constructor will always generate a new node each time we call,inside of it has a value (data), and have no left and right reference (null)
    Node(int inputData){
        this->left = NULL;
        this->data = inputData;
        this->right = NULL;
    }
};

void inOrder(Node *currNode){
    if(currNode==NULL)
        return;

    /* 
    traverse left child first 
    untill it hits the
    base case
    */
    inOrder(currNode->left);

    /*
    after we hits the basecase, we print the data
    */
    cout << currNode->data << " ";

    /*
    we print the data, 
    then we traverse right child
    */
    inOrder(currNode->right);

    return;
}

void preOrderRecursive(Node *currentNode){
    if(currentNode == NULL)
        return;
    printf("%d ",currentNode->data);
    preOrderRecursive(currentNode->left);
    preOrderRecursive(currentNode->right);
    return;
}

int main(){
    /*
    preOrder : 10 7 6 1 8 9 11 20 14 22 (Node Left Right)
    inOrder : 1 6 7 8 9 10 11 14 20 22 (Left Node Right)
    expected ouput:
    [10,7,11,6,8,null,20,1,null,null,9,14,22]

    We know:
    - 10 is the root. We know this because of the preOrder traversal--preOrder traversal always print root first.

    - 1 6 7 8 9 is left child(a) of root
    - 11 14 20 22 is right child(b) of root

    --1 7 is the root of left child(a). We know from again "preOrder traversal" 10(root) -> 7(left child of root)
    -- from point (--1) we can derive children of root (7), 1 6 is the left children of root (7). We know this from "inOrder traversal" [1 6] left [7] node
    so on and so forth the pattern will be same for the next operation
    */

    // just try to draw the tree so that you will understand


	return 0;
}

/*
https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/

https://www.youtube.com/watch?v=PoBGyrIWisE&list=PLdo5W4Nhv31bbKJzrsKfMpo_grxuLl8LU&index=55
5.7 Construct Binary Tree from Preorder and Inorder traversal with example | Data structures

*/