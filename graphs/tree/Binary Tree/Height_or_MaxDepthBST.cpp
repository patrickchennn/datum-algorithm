#include <iostream>
#include <queue>
using std::cout;
using std::endl;

class TreeNode{
public:
    TreeNode *left;
    int data;
    TreeNode *right;

    // // This constructor will always generate a node that has a value in it (data) and have no left and right reference (null)

    /* Node visualize
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

void insert(TreeNode **rootRef,int inputData);
void levelOrder(TreeNode *root);

// really getHeightDFS & getHeightDFS2 they are the same, the only difference is getHeightDFS2 uses a variable
int getHeightDFS2(TreeNode *root){
    if(!root)
        return -1;
    int left = getHeightDFS2(root->left);
    int right = getHeightDFS2(root->right);
    
    // if(left > right){
    //     return (left+1);
    // }else{
    //     return (right+1);
    // }
    
    // OR
    return std::max(
        left+1,
        right+1
    );
}

int getHeightDFS(TreeNode *root){
    if(!root)
        return -1;

    return std::max(
        getHeightDFS(root->left),

        getHeightDFS(root->right)
    )+1;

}

int getHeightBFS(TreeNode *root){

}

int main(){
    TreeNode *root = new TreeNode(7);

    insert(&root,4);
    insert(&root,1);
    insert(&root,6);

    insert(&root,9);
    levelOrder(root);
    cout << endl;

    int res = getHeightDFS2(root);
    cout << res << endl; // 2

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

void insert(TreeNode **rootRef,int inputData){
    if(!(*rootRef)){
        *rootRef = new TreeNode(inputData);
    }
    else if(inputData <= (*rootRef)->data)
        insert(&(*rootRef)->left,inputData);
    else
        insert(&(*rootRef)->right,inputData);

    return;
}

/*
Important note: The Height of every binary tree with "single node/leaf node" is taken as zero. So, if you at leaf node and get confused why it's returning 0? well we define single node/leaf node as zero value


each time the recursive call returns, the value will be incremented by 1.

https://www.youtube.com/watch?v=_pnqMz5nrRs&list=PL2_aWCzGMAwI3W_JlcBbtYTwiQSsOTa6P&index=31
Find height of a binary tree

https://www.geeksforgeeks.org/write-a-c-program-to-find-the-maximum-depth-or-height-of-a-tree/

https://www.youtube.com/watch?v=_O-mK2g_jhI

https://leetcode.com/problems/maximum-depth-of-binary-tree/
*/