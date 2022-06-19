#include <iostream>
#include <climits>
using std::cout;
using std::endl;

class TreeNode{
public:
    TreeNode *left;
    int data;
    TreeNode *right;
    TreeNode(int inputData){
        this->left = NULL;
        this->data = inputData;
        this->right = NULL;
    }
};
void insert(TreeNode **rootRef,int inputData);

bool isTreeNodeEmpty(TreeNode **rootRef){
    if(!(*rootRef))
        return true;

    return false;
}
// this function compare all left child value to its root value, if all left child value is lesser than its root, then left child satify the defintion of bst.
bool isSubtreeLesser(TreeNode *root,int val){
    if(isTreeNodeEmpty(&root))
        return true;

    if(
        root->data <= val &&

        isSubtreeLesser(root->left,val) && // check all left subtree

        isSubtreeLesser(root->right,val) // check all right subtree
    )
        return true;

    return false;
}

bool isSubtreeGreater(TreeNode *root,int val){
    if(isTreeNodeEmpty(&root))
        return true;

    if(
        root->data > val &&

        isSubtreeGreater(root->left,val) &&

        isSubtreeGreater(root->right,val)
    )
        return true;

    return false;
}

bool isBST(TreeNode *root){
    if(isTreeNodeEmpty(&root)) return true;

    if(
        // subtree left
        isSubtreeLesser(root->left,root->data) &&

        // subtree right
        isSubtreeGreater(root->right,root->data) &&

        isBST(root->left) &&

        isBST(root->right)
    )
        return true;

    return false;
}

int main(){
    // tree 1
    TreeNode *root = new TreeNode(7);
    // left subtree
    insert(&root,4);
    insert(&root,1);
    insert(&root,6);

    // right subtree
    insert(&root,9);

    // inOrder(root);
    // puts("");
    cout << std::boolalpha << isBST(root) << endl;
	return 0;
}
/*

*/

void insert(TreeNode **rootRef,int inputData){
    if(!(*rootRef))
        *rootRef = new TreeNode(inputData);
    else if(inputData <= (*rootRef)->data)
        insert(&(*rootRef)->left,inputData);
    else
        insert(&(*rootRef)->right,inputData);

    return;
}