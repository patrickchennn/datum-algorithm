#include <iostream>
#include <queue>
using std::cout;
using std::endl;

class TreeNode{
public:
    TreeNode *left;
    int data;
    TreeNode *right;
    int height;

    /* TreeNode visualize
    |--------------------|
    | NULL | data | NULL |
    |--------------------|
    */
    TreeNode(int inputData){
        this->left = NULL;
        this->data = inputData;
        this->right = NULL;
        this->height = 0;
    }
};

void levelOrder(TreeNode *root);
void preOrder(TreeNode *root);

int getHeight(TreeNode *root){
    if(!root)
        return -1;

    return std::max(
        getHeight(root->left),

        getHeight(root->right)
    )+1;

}

TreeNode *rightRotate(TreeNode *currRoot){
	puts("right rotation----------");
	TreeNode *median = currRoot->left;
	TreeNode *T2 = median->right;

	printf("median = currRoot -> %d = %d\n",median->data,currRoot->data);
	printf("T2 = %d\n\n",T2);
	// perform rotation
	median->right = currRoot;
	currRoot->left = T2;
	

    // Update heights
	currRoot->height = getHeight(currRoot);
	median->height = getHeight(currRoot);

	return median;
}

TreeNode *leftRotate(TreeNode *currRoot){
	puts("left rotation----------");
	TreeNode *median = currRoot->right;
	TreeNode *T2 = median->left;
	
	printf("median = currRoot -> %d = %d\n",median->data,currRoot->data);
	printf("T2 = %d\n\n",T2);

    // Perform rotation
	median->left = currRoot; // this is gonna be our new root
	currRoot->right = T2;

    // Update heights
	currRoot->height = getHeight(currRoot);
	median->height = getHeight(currRoot);

	return median;
}

int getBalanceFactor(TreeNode *N){
	if (!N)
		return 0;
	return getHeight(N->left)-getHeight(N->right);
}

TreeNode* insert(TreeNode* root, int data){
	// 1. Perform normal BST insertion
	if(!root)
        root = new TreeNode(data);

	if (data < root->data)
		root->left = insert(root->left, data);

	else if (data > root->data)
		root->right = insert(root->right, data);

	else
		return root;

    /* 2. Update the height of each current node */
	root->height = getHeight(root);


	/* 3. Get the balance factor of each current node to check whether this node became unbalanced or not. balanceFactor of node n must in ∈ of {-1,0,1} */
	int balanceFactor = getBalanceFactor(root);

	// 4. If root becomes unbalanced, then there are 4 cases

	// 4.1. Left Left Case/left weight tree/unbalanced left tree
	/*
	To check whether it is left left case or not, compare the newly inserted data with the data in left subtree root. 
	*/
	if (balanceFactor > 1 && data < root->left->data){
		puts("left weight tree");
		printf("unbalanced at value %d & bf = %d\n",root->data,balanceFactor);

		return rightRotate(root);
	}

	// 4.2. Right Right Case/right weight tree/unbalanced right tree
	/*
	To check whether it is Right Right case or not, compare the newly inserted data with the data in right subtree root. 
	*/
	if (balanceFactor < -1 && data > root->right->data){
		puts("right weight tree");
		printf("unbalanced at value %d & bf = %d\n",root->data,balanceFactor);

		return leftRotate(root);
	}

	// 4.3. Left Right Case
	if (balanceFactor > 1 && data > root->left->data){
		puts("left right case");
		printf("unbalanced at value %d & bf = %d\n",root->data,balanceFactor);

		root->left = leftRotate(root->left);
		return rightRotate(root);
	}

	// 4.4. Right Left Case
	if (balanceFactor < -1 && data < root->right->data){
		puts("right left case");
		printf("unbalanced at value %d & bf = %d\n",root->data,balanceFactor);

		root->right = rightRotate(root->right); // perform right rotation first

		return leftRotate(root); // after that we can perfrom left rotation
	}

	/* return the (unchanged) root pointer */
	return root;
}

int main(){
	TreeNode *root = NULL;

// Case 1
// Left unbalanced tree/left-left case --> Right rotation
    // root = insert(root,30);
    // root = insert(root,20);
    // root = insert(root,10);

// Case 2
// Right unbalanced tree/right-right case --> Left rotation
	// root = insert(root,10);
	// root = insert(root,20);
	// root = insert(root,30);

// Case 3
// right-left case
	// root = insert(root,20);
	// root = insert(root,30);
	// root = insert(root,25);

// Case 4
// left-right case
	// root = insert(root,20);
	// root = insert(root,10);
	// root = insert(root,15);

// Case 5 (https://www.youtube.com/watch?v=_8qqlVH5NC0&list=PLdo5W4Nhv31bbKJzrsKfMpo_grxuLl8LU&index=62) Recomended
    root = insert(root, 14);
    root = insert(root, 17);
    root = insert(root, 11);
    root = insert(root, 7);
    root = insert(root, 53);
    root = insert(root, 4);
	root = insert(root, 13);
	root = insert(root, 12);
	root = insert(root, 8);
	root = insert(root, 60);
	root = insert(root, 19);
	root = insert(root, 16);
	root = insert(root, 20);

	// levelOrder(root);
	preOrder(root);
    cout << endl;
	
	return 0;
}

/*
10=a
  \
  20=median
    \
    30=b

20 is median value of 10 20 30, and we want this median to become our new root. I.E. Median must sit between a and b (a < median < b) to satisfy the definition of BST.

condition that we know:
a<b ; median<b or b>median; a<median
<=> a < (b and median)

after we perfrom left rotation, we still didn't broke our condition.
	20=median
	/ \
10=a  30=b

Note: after inserting each node we suppose to each its balance factor
*/

/* resources
https://en.wikipedia.org/wiki/AVL_tree

https://www.hackerrank.com/challenges/self-balancing-tree/problem?isFullScreen=false (problem)

https://www.geeksforgeeks.org/avl-tree-set-1-insertion/ (code implementation)

https://www.tutorialspoint.com/data_structures_algorithms/avl_tree_algorithm.htm (recommended)

https://www.youtube.com/watch?v=YWqla0UX-38&list=PLdo5W4Nhv31bbKJzrsKfMpo_grxuLl8LU&index=62
5.13 AVL tree - Insertion, Rotations(LL, RR, LR, RL) with example | data structure

*/

void preOrder(TreeNode *root)
{
    if(root != NULL)
    {
        cout << root->data << " ";
        preOrder(root->left);
        preOrder(root->right);
    }
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
