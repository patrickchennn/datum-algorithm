#include <bits/stdc++.h>
using namespace std;

class Node{
public:
    Node *left;
    int data;
    Node *right;
    Node(int inputData){
        this->left = NULL;
        this->data = inputData;
        this->right = NULL;
    }
};

unsigned int countNode(Node *currNode){
    if(!currNode)
        return 0;
    queue<Node *> q;
    
}

int main(){
    // // tree 2
    // Node *root = new Node(1);
    // // preOrder ouput: 1 2 4 5 3
    // root->left = new Node(2);
    // root->right = new Node(3);
    // root->left->left = new Node(4);
    // root->left->right = new Node(5);

    // trees 2
    // preOrder ouput: 10 7 6 1 8 9 11 20 14 22
    Node *root = new Node(10);
    // left child
    root->left = new Node(7);
    root->left->left = new Node(6);
    root->left->left->left = new Node(1);

    root->left->right = new Node(8);
    root->left->right->right = new Node(9);

    // right child
    root->right = new Node(11);
    root->right->right = new Node(20);
    root->right->right->right = new Node(22);
    root->right->right->left = new Node(14);


    // cout << endl;
	return 0;
}

/*

*/