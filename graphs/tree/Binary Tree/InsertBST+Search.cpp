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

void insert(TreeNode **rootRef,int inputData){
    if(!(*rootRef))
        *rootRef = new TreeNode(inputData);

    else if(inputData <= (*rootRef)->data)
        insert(&(*rootRef)->left,inputData);
    else
        insert(&(*rootRef)->right,inputData);

    return;
}

bool search(TreeNode *root,int target){
    // if(!root) // if node is empty
    //     return false;

    // else if(root->data == target) // if we meet our targeted value 
    //     return true;

    // else if(target <= root->data) // if target value <= current tree node value
    //     return search(root->left,target);
        
    // else // if target >= current tree nodevalue
    //     return search(root->right,target);

    // OR

    if(!root || root->data==target)
        return root;
    return (target <= root->data) ?
        search(root->left,target) : search(root->right,target);
}

bool searchI(TreeNode *root,int target){
    
    while(root != NULL && root->data != target){
        root = (target < root->data) ?
            root->left : root->right;
    }

    if(root!=NULL)
        return true;

    return false;
}

int main(){
    TreeNode *root = new TreeNode(7);
    // left child
    insert(&root,4);
    insert(&root,1);
    insert(&root,6);

    // right child
    insert(&root,9);

    levelOrder(root);
    cout << endl;

    int num = 6;
    cout << std::boolalpha << searchI(root,num) << endl;
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