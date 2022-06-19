#include <bits/stdc++.h>
using std::cout;
using std::endl;
using std::vector;
using std::cin;

class Node{
public:
    int data;
    Node *nextNode;
};

void InsertNodeAtTail(Node **headReference,int data);

// print ll interative method
void printLL(Node *head){
    while(head != NULL){
        printf("%d -> ",head->data);
        head = head->nextNode;
    }
    puts("NULL");
    // printf("expect 0/null %d\n",head);
}

// print ll recursive method
void printLLRecursive(Node *head){
    if(head==NULL){
        // this will results segfault because we are accessing unallowed element/address
        // cout << head->data << endl;
        puts("NULL");
        return;
    }
    printf("%d -> ",head->data);
    printLLRecursive(head->nextNode);
}

// print ll in reverse recursive
void printLLReverse(Node *head){
    if(head==NULL)
        return;
    
    printLLReverse(head->nextNode);
    printf("%d -> ",head->data);
    puts("xx");

    // OR

    // if(head != NULL){
    //     printLLReverse(head->nextNode);
    //     printf("%d -> ",head->data);
    // }
    // either way works! I prefer the first one

}

int main(){
    Node* head = NULL;

    InsertNodeAtTail(&head,1);
    InsertNodeAtTail(&head,2);
    InsertNodeAtTail(&head,3);

    // printLL(head);
    // printLLRecursive(head);
    printLLReverse(head);
    puts("NULL");
	return 0;
}

void InsertNodeAtTail(Node **headReference,int dataInput){
    Node *newNode = new Node();
    newNode->data = dataInput;
    newNode->nextNode = NULL;

    if((*headReference)==NULL){
        *headReference = newNode;
        return;
    }
    // we need to traverse the ll untill end-1 because we want to insert a new node at the end, and *traverseList will helps us to update the link
    Node *traverseList = new Node();
    traverseList = *headReference;
    while(traverseList->nextNode != NULL)
        traverseList = traverseList->nextNode;
    traverseList->nextNode = newNode;
    return;
}

/*
https://www.youtube.com/watch?v=K7J3nCeRC80
Print elements of a linked list in forward and reverse order using recursion

*/