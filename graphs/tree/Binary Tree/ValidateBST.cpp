#include <iostream>
#include <climits>
using std::cout;
using std::endl;

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

void insert(TreeNode **rootRef,int inputData);

void inOrder(TreeNode *currNode);

// Note: This method is not applicable if there are duplicate elements with value INT_MIN or INT_MAX.
bool isBSTUtil(TreeNode *root,int min,int max);

bool isBST(TreeNode *root){
    return(isBSTUtil(root,INT_MIN,INT_MAX));
}

bool isBSTUtil(TreeNode *root,int min,int max){
    if(root==NULL)
        return true;

    if(root->data <= min || root->data >= max)
        return false;
    return 
        isBSTUtil(root->left, min, root->data) &&
        isBSTUtil(root->right, root->data, max);
}

int main(){
    // tree 1
    TreeNode *root = new TreeNode(7);
    // left subtree
    insert(&root,4);
    insert(&root,1);
    insert(&root,6);

    // right subtree
    insert(&root,9);

    // inOrder(root);
    // puts("");
    cout << std::boolalpha << isBST(root) << endl;
	return 0;
}

/*
true=yes it is a bst
false = no it is not a bst

Check if a binary tree is binary search tree or not
https://www.youtube.com/watch?v=yEwSGhSsT0U&list=PL2_aWCzGMAwI3W_JlcBbtYTwiQSsOTa6P&index=35

problem:
https://leetcode.com/problems/validate-binary-search-tree/
https://www.hackerrank.com/challenges/is-binary-search-tree/problem?isFullScreen=false


https://www.geeksforgeeks.org/a-program-to-check-if-a-binary-tree-is-bst-or-not/

*/

void insert(TreeNode **rootRef,int inputData){
    if(!(*rootRef))
        *rootRef = new TreeNode(inputData);
    else if(inputData <= (*rootRef)->data)
        insert(&(*rootRef)->left,inputData);
    else
        insert(&(*rootRef)->right,inputData);

    return;
}

void inOrder(TreeNode *currNode){
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