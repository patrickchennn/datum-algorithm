#include <bits/stdc++.h>
using namespace std;

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

void inOrder(TreeNode *root);

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

int main(){
    TreeNode *root = NULL;

    // root
    insert(&root,1);
    // cout << "root address " << root << endl;
    
    // left child of root
    insert(&root,-1);
    printf("%p %p %d %p\n",
        root->left,
        root->left->left, // NULL
        root->left->data, // -1
        root->left->right // NULL
    );

    // right child of root
    insert(&root,3);
    printf("%p %p %d %p\n",
        root->right,
        root->right->left, // NULL
        root->right->data, // 3
        root->right->right // NULL
    );

    printf("%p %d %p\n",
        root->left, // contains address of left child
        root->data, // 1
        root->right // contains address of right child
    );
    // the patterns will same as you insert more and more data...
	return 0;
}

void inOrder(TreeNode *root){
    // Inorder traversal: Left TreeNode Right
    if(!root)
        return;
    inOrder(root->left);
    cout << root->data << " ";
    inOrder(root->right);
    
    return;
}

/*
https://www.youtube.com/watch?v=COZK7NATh4k&list=PL2_aWCzGMAwI3W_JlcBbtYTwiQSsOTa6P&index=28
Binary search tree - Implementation in C/C++

*/