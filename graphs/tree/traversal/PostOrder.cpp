#include <bits/stdc++.h>
using namespace std;

class Node{
public:
    Node *left;
    int data;
    Node *right;
    Node(int inputData){
        this->left = NULL;
        this->data = inputData;
        this->right = NULL;
    }
};

// Left Right Node
void postOrder(Node *currentNode){
    if(currentNode == NULL)
        return;
        
    postOrder(currentNode->left);

    postOrder(currentNode->right);

    printf("%d ",currentNode->data);

    return;
}

void postOrderIterative(Node *root){
    
}

int main(){
    // // tree 1
    // Node *root = new Node(1);
    // // postOrder ouput: 4 5 2 3 1
    // root->left = new Node(2);
    // root->right = new Node(3);
    // root->left->left = new Node(4);
    // root->left->right = new Node(5);

    // trees 2
    // postOrder ouput: 1 6 9 8 7 14 22 20 11 10
    Node *root = new Node(10);
    // left child
    root->left = new Node(7);
    root->left->left = new Node(6);
    root->left->left->left = new Node(1);

    root->left->right = new Node(8);
    root->left->right->right = new Node(9);

    // right child
    root->right = new Node(11);
    root->right->right = new Node(20);
    root->right->right->right = new Node(22);
    root->right->right->left = new Node(14);


    postOrder(root);
    cout << endl;
	return 0;
}

/*
https://www.geeksforgeeks.org/tree-traversals-inorder-preorder-and-postorder/
https://www.geeksforgeeks.org/iterative-postorder-traversal-using-stack/

https://www.youtube.com/watch?v=BHB0B1jFKQc&t=679s
Binary Tree Bootcamp: Full, Complete, & Perfect Trees. Preorder, Inorder, & Postorder Traversal.

https://www.hackerrank.com/challenges/tree-postorder-traversal/problem?isFullScreen=true
*/