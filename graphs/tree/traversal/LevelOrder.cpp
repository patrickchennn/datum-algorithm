#include <iostream>
#include <queue>
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
// 10 7 11 6
void levelOrder(TreeNode *root){
    if(!root)
        return;

    std::queue<TreeNode *> Q;

    Q.push(root);

    while(!Q.empty()){
        TreeNode *currTreeNode = Q.front();

        cout << currTreeNode->data << " ";

        if(currTreeNode->left != NULL) // same
        // if(currTreeNode->left) // same
            Q.push(currTreeNode->left);

        if(currTreeNode->right != NULL) // same
        // if(currTreeNode->right) // same 
            Q.push(currTreeNode->right);

        Q.pop();
        
    }
    cout << endl;
}

int main(){
    // levelOrder ouput: 10 7 11 6 8 20 1 9 14 22
    TreeNode *root = new TreeNode(10);
    // left child
    root->left = new TreeNode(7);
    root->left->left = new TreeNode(6);
    root->left->left->left = new TreeNode(1);

    root->left->right = new TreeNode(8);
    root->left->right->right = new TreeNode(9);

    // right child
    root->right = new TreeNode(11);
    root->right->right = new TreeNode(20);
    root->right->right->right = new TreeNode(22);
    root->right->right->left = new TreeNode(14);


    levelOrder(root);
    cout << endl;
	return 0;
}

/*
the idea is when we at a particular Treenode, then we need always to keep/push left and right child into queue if they exist/not null

with queue we could print the data sequentially from left to right, because we know that queue is fifo (first in first out)


https://www.youtube.com/watch?v=86g8jAQug04&list=PL2_aWCzGMAwI3W_JlcBbtYTwiQSsOTa6P&index=33
Binary tree: Level Order Traversal

https://leetcode.com/problems/binary-tree-level-order-traversal/

https://en.wikipedia.org/wiki/Breadth-first_search
*/