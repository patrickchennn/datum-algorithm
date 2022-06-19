#include <bits/stdc++.h>
using namespace std;

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

int main(){
    // create root
    TreeNode *root = new TreeNode(4);
    printf("%p %d %p\n",
        root->left,
        root->data, // 4
        root->right
    );
/* following is the tree above statement
          root(data)
         /   \
root->left   root->right

    4
   / \
NULL  NULL
*/

    root->left = new TreeNode(2);
    printf("%p %p %d %p\n",
        root->left,
        root->left->left,
        root->left->data, // 2
        root->left->right
    );
/* 2 become left children of 2(root) or root has left children (2)
                    root(data)
                    /         \
            root->left(data)   root->right
            /                       \
    root->left->left            root->left-right

            4
           / \
          2  NULL
         / \  
      NULL  NULL
*/
    root->right = new TreeNode(3);

/* 3 become right children of 4(root)
               4
             /   \
           /       \
          2         3
         / \        /\
      NULL NULL NULL NULL
2 and 3 become left and right children of 4(root)*/

    root->left->left = new TreeNode(9);
    /* 4 becomes left child of 2
               4
             /   \
            /     \
           2       3
          / \     / \
         9  NULL NULL NULL
        / \
     NULL NULL
    */
	return 0;
}

/*
https://www.geeksforgeeks.org/binary-tree-set-1-introduction/

https://www.tutorialspoint.com/data_structures_algorithms/tree_data_structure.htm
*/