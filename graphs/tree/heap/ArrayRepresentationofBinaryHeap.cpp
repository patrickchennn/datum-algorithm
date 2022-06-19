#include <iostream>
#include <math.h> // for floor function
#include <queue> // for bfs
#include <vector> // for storing binary tree value into arr
using std::cout;
using std::endl;

class TreeNode{
public:
    TreeNode *left;
    char data;
    TreeNode *right;

    // // This constructor will always generate a Treenode that has a value in it (data) and have no left and right reference (null)

    /* TreeNode visualize
    |--------------------|
    | NULL | data | NULL |
    |--------------------|
    */
    TreeNode(char inputData){
        this->left = NULL;
        this->data = inputData;
        this->right = NULL;
    }
};

void insert(TreeNode **rootRef,char inputData);
void levelOrder(TreeNode *root);
void toArray(TreeNode *root,std::vector<char> &arrBT);
void print1dVector(std::vector<char> &arr);

int leftChild(int i){
    return 2*i+1;
}

int rightChild(int i){
    return 2*i+2;
}

int parent(int i){
    return floor((i-1)/2);
}

int main(){
    // for graph representation click youtube link below
	TreeNode *root = new TreeNode('A');
	insert(&root,'B');
	insert(&root,'C');
	insert(&root,'D');
	insert(&root,'E');
	insert(&root,'F');
	insert(&root,'G');
	insert(&root,'H');
	insert(&root,'I');
	// levelOrder(root);

	std::vector<char> arrBT;
	toArray(root,arrBT);
	print1dVector(arrBT);

	printf("leftChild: %c\n",arrBT[leftChild(1)]);
	printf("rightChild: %c\n",arrBT[rightChild(1)]);
	printf("parent: %c\n",arrBT[parent(3)]);
	
	return 0;
}

void print1dVector(std::vector<char> &arr){
	for(int i=0; i<arr.size(); i++){
		cout << i << " ";
	}
	cout << endl;
	for(char &c : arr)
		cout << c << " ";
	cout << endl;
}

void toArray(TreeNode *root,std::vector<char> &arrBT){
    // if root==NULL // same
    if(!root) // same
        return;

    std::queue<TreeNode *> Q;

    Q.push(root);

    while(!Q.empty()){
        TreeNode *currTreeNode = Q.front();

        arrBT.push_back(currTreeNode->data);

        if(currTreeNode->left != NULL) // same
        // if(currTreeNode->left) // same
            Q.push(currTreeNode->left);

        if(currTreeNode->right != NULL) // same
        // if(currTreeNode->right) // same 
            Q.push(currTreeNode->right);

        Q.pop();
        
    }
	    cout << endl;
}

// This is the same as BFS.
void levelOrder(TreeNode *root){
    if(!root)
        return;

    std::queue<TreeNode *> Q;

    Q.push(root);

    while(!Q.empty()){
        TreeNode *currTreeNode = Q.front();

        cout << currTreeNode->data << " ";

        if(currTreeNode->left != NULL) // same
        // if(currTreeNode->left) // same
            Q.push(currTreeNode->left);

        if(currTreeNode->right != NULL) // same
        // if(currTreeNode->right) // same 
            Q.push(currTreeNode->right);

        Q.pop();
        
    }
	    cout << endl;
}

void insert(TreeNode **rootRef,char inputData){
    if(!(*rootRef))
        *rootRef = new TreeNode(inputData);

    else if(inputData <= (*rootRef)->data)
        insert(&(*rootRef)->left,inputData);
    else
        insert(&(*rootRef)->right,inputData);

    return;
}

/*
https://www.geeksforgeeks.org/array-representation-of-binary-heap/

https://www.youtube.com/watch?v=zDlTxrEwxvg&list=PLdo5W4Nhv31bbKJzrsKfMpo_grxuLl8LU&index=52
5.4 Binary Tree Representation |Array representation of binary tree | Data Structure

https://www.programiz.com/dsa/heap-data-structure
*/