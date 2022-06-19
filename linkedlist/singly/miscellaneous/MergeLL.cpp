/* C++ program to merge two sorted linked lists */
#include <bits/stdc++.h>
using namespace std;

/* Link list node */
class Node{
public:
	int data;
	Node* nextNode;
};

void InsertNodeFromTail(Node** head_ref, int new_data);
void printList(Node *node);

Node *mergeRecursive(Node *llA, Node *llB){
    if(llA==NULL)
        return llB;
    if(llB==NULL)
        return llA;

    Node *headForMergeLL = NULL;
    if(llA->data < llB->data){
        headForMergeLL = llA;
        headForMergeLL->nextNode = mergeRecursive(llA->nextNode,llB);
    }else{
        headForMergeLL = llB;
        headForMergeLL->nextNode = mergeRecursive(llA,llB->nextNode);
    }
    return headForMergeLL;
}

int main()
{
	Node* a = NULL;
	Node* b = NULL;

	InsertNodeFromTail(&a, 5);
	InsertNodeFromTail(&a, 10);

	InsertNodeFromTail(&b, 2);
	InsertNodeFromTail(&b, 3);

	// printList(a);
    // printList(b);

    Node *results = mergeRecursive(a,b);
	printList(results);

	return 0;
}

/*
https://www.youtube.com/watch?v=j_UNYW6Ap0k
Merge two sorted Linked Lists to form a new Sorted Linked List

*/

void InsertNodeFromTail(Node **headReference, int data){
    Node *newNode = new Node();
    newNode->data = data;
    newNode->nextNode = NULL;

    if((*headReference)==NULL){
        *headReference = newNode;
        return;
    }
    // we need to traverse the ll untill end-1 because we want to insert a new node at the end, and *traverseList will helps us to update the link
    Node *traverseList = *headReference;
    while(traverseList->nextNode != NULL){
        traverseList = traverseList->nextNode;
    }
    traverseList->nextNode= newNode;
    return;
}

void printList(Node *node)
{
	while (node!=NULL)
	{
		cout<<node->data<<" ";
		node = node->nextNode;
	}
    puts("");
}