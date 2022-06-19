#include <iostream>
#include <queue>
using std::cout;
using std::endl;

class TreeNode{
public:
    TreeNode *left;
    int data;
    TreeNode *right;

    // // This constructor will always generate a new Treenode such that has a value in it (data) and have no left and right reference (null)

    /* TreeNode visualize
    |--------------------|
    | NULL | data | NULL |
    |--------------------|
    */
    TreeNode(int inputData){
        this->left = NULL;
        this->data = inputData;
        this->right = NULL;
    }
};
void levelOrder(TreeNode *root);

TreeNode *insert(TreeNode *root,int inputData){
    if(!root){
        root = new TreeNode(inputData);
    }else if(inputData <= root->data){
        root->left = insert(root->left,inputData);
    }else{
        root->right = insert(root->right,inputData);
    }
    return root;
}


int main(){
    TreeNode *root = NULL;

// Case 1
// Left unbalanced tree(problem) --> Right rotation(solution)
    // root = insert(root,30);
    // root = insert(root,20);
    // root = insert(root,10);

// Case 2
// Right unbalanced tree(problem) --> Left rotation(solution)
	root = insert(root,10);
	root = insert(root,20);
	root = insert(root,30);

    levelOrder(root);
    cout << endl;

	return 0;
}

void levelOrder(TreeNode *root){
    if(!root)
        return;

    std::queue<TreeNode *> Q;

    Q.push(root);

    while(!Q.empty()){
        TreeNode *currentTreeNode2 = Q.front();

        cout << currentTreeNode2->data << " "; // 10 

        if(currentTreeNode2->left != NULL) // same
        // if(currentTreeNode2->left) // same
            Q.push(currentTreeNode2->left);

        if(currentTreeNode2->right != NULL) // same
        // if(currentTreeNode2->right) // same 
            Q.push(currentTreeNode2->right);

        Q.pop();
        
    }
}

/*
https://www.youtube.com/watch?v=COZK7NATh4k&list=PL2_aWCzGMAwI3W_JlcBbtYTwiQSsOTa6P&index=28
Binary search tree - Implementation in C/C++

https://www.youtube.com/watch?v=hWokyBoo0aI&list=PL2_aWCzGMAwI3W_JlcBbtYTwiQSsOTa6P&index=29
*/