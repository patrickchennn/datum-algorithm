#include <bits/stdc++.h>
using namespace std;

class TreeNode{
public:
    TreeNode *left;
    int data;
    TreeNode *right;
    TreeNode(int inputData){
        this->left = NULL;
        this->data = inputData;
        this->right = NULL;
    }
};

/* Using recursion
time : O(n), where n is number of TreeNode in the tree
space: O(h), where h is height of the tree
*/
void preOrderRecursive(TreeNode *currTreeNode){

    if(currTreeNode == NULL)
        return;

    printf("%d ",currTreeNode->data);

    preOrderRecursive(currTreeNode->left);

    preOrderRecursive(currTreeNode->right);

    return;
}
// 1 2 4 5 3
/*  Using stack
time : O(n), where n is number of TreeNode in the tree
space: O(n), we need n number stack call to keep each data
*/
void preOrderIterative(TreeNode *root){
    if(!root) return;
// 10 7 6 1 8 9 11 20 14 22
    stack<TreeNode *> treeNodeStack;
    treeNodeStack.push(root);

    while(!treeNodeStack.empty()){
        TreeNode *currTreeNode = treeNodeStack.top();

        cout << currTreeNode->data << " ";

        treeNodeStack.pop();

        if(currTreeNode->right != NULL) // same
        // if(currTreeNode->right) // same 
            treeNodeStack.push(currTreeNode->right);

        if(currTreeNode->left != NULL) // same
        // if(currTreeNode->left) // same
            treeNodeStack.push(currTreeNode->left);
    }
    // Note that right child is pushed first so that left is processed first. Remember stack(lifo)

    // if you get confused just debug it or try to draw each execution on a paper
}

void morrisPreOrder(TreeNode *currTreeNode){}

// Preorder: TreeNode Left Right
int main(){
    // // tree 1
    TreeNode *root = new TreeNode(1);
    // preOrder ouput: 1 2 4 5 3
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    // trees 2
    // preOrder ouput: 10 7 6 1 8 9 11 20 14 22
    // TreeNode *root = new TreeNode(10);
    // // left child
    // root->left = new TreeNode(7);
    // root->left->left = new TreeNode(6);
    // root->left->left->left = new TreeNode(1);

    // root->left->right = new TreeNode(8);
    // root->left->right->right = new TreeNode(9);

    // // right child
    // root->right = new TreeNode(11);
    // root->right->right = new TreeNode(20);
    // root->right->right->right = new TreeNode(22);
    // root->right->right->left = new TreeNode(14);

    preOrderRecursive(root);
    cout << endl;

    preOrderIterative(root);
    cout << endl;
	return 0;
}

/*

// recursive approach
https://www.geeksforgeeks.org/tree-traversals-inorder-preorder-and-postorder/


// Binary Tree Bootcamp: Full, Complete, & Perfect Trees. Preorder, Inorder, & Postorder Traversal.
https://www.youtube.com/watch?v=BHB0B1jFKQc&t=679s

// iterative approach
https://www.geeksforgeeks.org/iterative-preorder-traversal/

// problem
https://www.hackerrank.com/challenges/tree-preorder-traversal/problem?isFullScreen=false
https://leetcode.com/problems/binary-tree-preorder-traversal/

*/