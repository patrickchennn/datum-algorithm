#include <iostream>
#include <stack>
using std::cout;
using std::endl;

class Node{
public:
    Node *left;
    int data;
    Node *right;

    // This constructor will always generate a node that has a value in it (data) and have no left and right reference (null)
    Node(int inputData){
        this->left = NULL;
        this->data = inputData;
        this->right = NULL;
    }
};

void inOrder(Node *currNode){
    if(currNode==NULL)
        return;

    /* 
    traverse left child first 
    untill it hits the
    base case
    */
    inOrder(currNode->left);

    /*
    after we hits the basecase, we print the data
    */
    cout << currNode->data << " ";

    /*
    we print the data, 
    then we traverse right child
    */
    inOrder(currNode->right);

    return;
}

void inOrderIterative(Node *root){
    std::stack<Node *> S;
    Node *currNode = root;


    while(currNode != NULL || !S.empty()){
// we need to push root into stack first because we don't want to lose root reference, if we lose our root then how we can print right subtree?

//after that we push all left child to stack and set currNode = currNode->left until current is NULL, why we need to set that? because we prioritize left child instead of right child, that's how inorder traversal works? left node right.
        while (currNode != NULL){
            S.push(currNode);
            currNode = currNode->left;
        }
        currNode = S.top();
        S.pop();

        cout << currNode->data << " ";
        // point our currNode into right node if right node exist/not null. if currNode point to right node, then we can again check ALL left node first. if ALL left child exist/not null, then we print it.
        currNode = currNode->right;
    }

}
// 4 2
int main(){
// Left Node Right
    // // tree 1
    // Node *root = new Node(1);
    // // inorder output : 4 2 5 1 3
    // root->left = new Node(2);
    // root->right = new Node(3);
    // root->left->left = new Node(4);
    // root->left->right = new Node(5);

    // // trees 2
    // // inOrder ouput: 1 6 7 8 9 10 11 14 20 22
    // Node *root = new Node(10);

    // // left child
    // root->left = new Node(7);

    // root->left->left = new Node(6);
    // root->left->left->left = new Node(1);

    // root->left->right = new Node(8);
    // root->left->right->right = new Node(9);

    // // right child
    // root->right = new Node(11);
    // root->right->right = new Node(20);
    // root->right->right->right = new Node(22);
    // root->right->right->left = new Node(14);

    //trees 3, for picture look for "inOrderStackAprroach" name, inside of this folder
    Node *root = new Node(1);
    // left child
    root->left = new Node(2);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->left->right->left = new Node(8);
    root->left->right->right = new Node(9);

    // right child
    root->right = new Node(3);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    // inOrder(root);
    // cout << endl;

    inOrderIterative(root);
    cout << endl;

	return 0;
}

/*

// Binary Tree Bootcamp: Full, Complete, & Perfect Trees. Preorder, Inorder, & Postorder Traversal.
https://www.youtube.com/watch?v=BHB0B1jFKQc&t=679s

// recursive approach
https://www.geeksforgeeks.org/tree-traversals-inorder-preorder-and-postorder/

// iterative approach
https://www.geeksforgeeks.org/inorder-tree-traversal-without-recursion/

// problem
https://www.hackerrank.com/challenges/tree-inorder-traversal/problem?isFullScreen=true
https://leetcode.com/problems/binary-tree-inorder-traversal/
*/