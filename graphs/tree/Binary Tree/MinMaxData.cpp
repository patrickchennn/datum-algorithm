#include <bits/stdc++.h>
using std::cout;
using std::endl;

class Node{
public:
    Node *left;
    int data;
    Node *right;

    // // This constructor will always generate a new node such that has a value in it (data) and have no left and right reference (null)

    /* Node visualize
    |--------------------|
    | NULL | data | NULL |
    |--------------------|
    */
    Node(int inputData){
        this->left = NULL;
        this->data = inputData;
        this->right = NULL;
    }
};

void inOrder(Node *root);
void insert(Node **rootRef,int inputData);

// not gonna copy the tree
// I just want to check if empty is empty or not. So, pass by address will be enough
bool treeIsEmpty(Node **rootRef){
    if(!(*rootRef))
        return true;
    return false;
}

int findMinIterative(Node *root){
    if(treeIsEmpty(&root)){
        puts("Tree is empty!");
        return -1;
    }
    while(root->left != NULL)
        root = root->left;
    return root->data;
}

int findMaxIterative(Node *root){
    if(treeIsEmpty(&root)){
        puts("Tree is empty!");
        return -1;
    }
    while(root->right != NULL)
        root = root->right;
    return root->data;
}

int findMinRecursive(Node *root){
    if(treeIsEmpty(&root)){
        puts("Tree is empty!");
        return -1;
    }

    // if(root->left == NULL)
    //     return root->data;
    // return findMinRecursive(root->left);

    // OR

    if(root->left != NULL)
        return findMinRecursive(root->left);
    return root->data;
}

int findMaxRecursive(Node *root){
    if(treeIsEmpty(&root)){
        puts("Tree is empty!");
        return -1;
    }

    // if(root->right == NULL)
    //     return root->data;
    // return findMaxRecursive(root->right);

    // OR
    
    if(root->right != NULL)
        return findMaxRecursive(root->right);
    return root->data;
}

int main(){
    Node *root = new Node(15);
    insert(&root,10);
    insert(&root,8);
    insert(&root,12);
    insert(&root,20);
    insert(&root,17);
    insert(&root,25);

    inOrder(root);
    puts("");

    printf("Min value: %d\n",findMinIterative(root));
    printf("Max value: %d\n",findMaxIterative(root));
    puts("------------------------ recursive");
    printf("Min value: %d\n",findMinRecursive(root));
    printf("Max value: %d\n",findMaxRecursive(root));
	return 0;
}

void inOrder(Node *root){
    // Inorder traversal: Left Node Right
    if(!root)
        return;
    inOrder(root->left);
    cout << root->data << " ";
    inOrder(root->right);

    return;
}

void insert(Node **rootRef,int inputData){
    if(!(*rootRef)){
        *rootRef = new Node(inputData);
    }
    else if(inputData <= (*rootRef)->data)
        insert(&(*rootRef)->left,inputData);
    else
        insert(&(*rootRef)->right,inputData);

    return;
}

/*
https://www.youtube.com/watch?v=Ut90klNN264&list=PL2_aWCzGMAwI3W_JlcBbtYTwiQSsOTa6P&index=30
Find min and max element in a binary search tree

Iterative
time: O(n), where n is number of node in the tree
space: O(1), because we only need 1 while loop

Recursive:
time: O(n), where n is number of node in the tree
space: O(n), because we need to allocate stack each time we do recursive call

*/