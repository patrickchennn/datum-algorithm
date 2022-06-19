#include <bits/stdc++.h>
using namespace std;

class Node{
public:
    Node *left;
    int data;
    Node *right;

    // set left and right as NULL is considered as a best practice? even though left and right by default 0x0(null), why I know that? debug it.

    Node(){
        this->left = NULL;
        this->right = NULL;
    }
};

Node *create(){
    int newData;
    Node *newNode = new Node();
    cin >> newData;

    // for simplicity I'm gonna use -1 for basecase, indeed, it will be much better if we didn't use the same data type to compare with
    if(newData==-1)
        return NULL;
    newNode->data = newData;

    printf("Enter a value for left child: ");
    puts("");
    newNode->left = create();

    printf("Enter a value for right child: ");
    puts("");
    newNode->right = create();
    return newNode;
}

int main(){
    Node *root = NULL;
    root = create();

    puts("root node");
    printf("%p %d %p\n\n",
        root->left,
        root->data,
        root->right
    );
    
    printf("address of left node: %p\n",root->left);
    printf("address of right node: %p\n",root->right);

    puts("left node of root");
    printf("%p %d %p\n\n",
        root->left->left,
        root->left->data,
        root->left->right
    );

    puts("right node of root");
    printf("%p %d %p\n\n",
        root->right->left,
        root->right->data,
        root->right->right
    );
	return 0;
}

/*
https://www.youtube.com/watch?v=6vt3PFRC11E&list=PLdo5W4Nhv31bbKJzrsKfMpo_grxuLl8LU&index=51
5.3 Binary Tree Implementation | Data Structures

*/