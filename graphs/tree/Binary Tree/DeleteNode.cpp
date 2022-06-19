#include <iostream>
#include <queue> // for levelOrder traversal
using std::cout;
using std::endl;

class TreeNode{
public:
    TreeNode *left;
    int data;
    TreeNode *right;

    // // This constructor will always generate a Treenode that has a value in it (data) and have no left and right reference (null)

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

void insert(TreeNode **rootRef,int inputData);
void levelOrder(TreeNode *root);

TreeNode *findMin(TreeNode *currNode){
    while(currNode->left != NULL)
        currNode = currNode->left;
    
    return currNode;
}

TreeNode *deleteTreeNode(TreeNode *root,int val){
    if(!root) // if(root==NULL)
        return root;

    else if(val < root->data)
        root->left = deleteTreeNode(root->left,val);

    else if(val > root->data)
        root->right = deleteTreeNode(root->right,val);
    
    // same as: else(val == root->data)
    else{ // we found the value that we want to delete

        // Case 1: No child/deleting leaf node
        if(!root->left && !root->right){ // if(root->left==NULL && root->right==NULL)
            delete root;
            root = NULL;
        }

        // Case 2: Exactly has one child. We'll handle 2 cases right and left
        else if(!root->right){ // if(root->right==NULL)
            TreeNode *currNode = root;
            root = root->left;
            delete currNode;
            currNode = NULL;
        }
        else if(!root->left){ // if(root->left==NULL)
            TreeNode *currNode = root;
            root= root->right;
            delete currNode;
            currNode = NULL;
        }

        // Case 3: 2 children
        else{
            TreeNode *currNode = findMin(root->right);
            root->data = currNode->data;
            root->right = deleteTreeNode(root->right,currNode->data);
        }
    }
    return root;
}

int main(){
    TreeNode *root = new TreeNode(10);
    // left child
    insert(&root,7);
    insert(&root,6);
    insert(&root,8);
    insert(&root,1);
    insert(&root,9);

    //right child
    insert(&root,11);
    insert(&root,20);
    insert(&root,14);
    insert(&root,22);

    levelOrder(root);
    cout << endl;

    int n = 7;
    root = deleteTreeNode(root,n);
    levelOrder(root);
    cout << endl;
    return 0;
}

/*
for case 3 you can either:
find min in right-subtree, copy the value in targetted node, delete duplicate from right-subtree 
OR 
find max in left-subtree,copy the value in targetted node, delete duplicate from left-subtree

Delete a node from Binary Search Tree
https://www.youtube.com/watch?v=gcULXE7ViZw&list=PL2_aWCzGMAwI3W_JlcBbtYTwiQSsOTa6P&index=37

*/

void levelOrder(TreeNode *root){
    if(!root)
        return;

    std::queue<TreeNode *> Q;

    Q.push(root);

    while(!Q.empty()){
        TreeNode *currNode = Q.front();
        cout << currNode->data << " ";

        if(currNode->left != NULL)
            Q.push(currNode->left);
        
        if(currNode->right != NULL)
            Q.push(currNode->right);

        Q.pop();
    }

}

void insert(TreeNode **rootRef,int inputData){
    if(!(*rootRef))
        *rootRef = new TreeNode(inputData);

    else if(inputData <= (*rootRef)->data)
        insert(&(*rootRef)->left,inputData);
    else
        insert(&(*rootRef)->right,inputData);

    return;
}
