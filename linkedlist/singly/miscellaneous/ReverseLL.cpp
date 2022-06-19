#include <iostream>
using std::cout;
using std::endl;

class Node{
public:
    int data;
    Node *nextNode;
};

void PrintLL(Node *head);
void InsertNodeFromTail(Node **headRef, int data);

// iterative 2
void ReverseLL2(Node **head){
    if((*head)==NULL||(*head)->nextNode == NULL) return;
    Node *curr = *head;
    Node *nextCurr = *head;
    Node *prevCurr = NULL;

    while(curr != NULL){
        nextCurr = nextCurr->nextNode;
        curr->nextNode = prevCurr; // reverse part
        prevCurr = curr;
        curr = nextCurr;
    }
    *head = prevCurr;
}

// iterative
void ReverseLL(Node **head){
// check if list is zero or list contains only 1 node
    if((*head)==NULL||(*head)->nextNode == NULL) return;

    Node *afterHead = new Node();
    Node *beforeHead = new Node();
    afterHead = *head;
    beforeHead = NULL;
    while(*head != NULL){
        afterHead = afterHead->nextNode;
        // afterHead = (*head)->nextNode;
        //this is where actual reversing happens
        (*head)->nextNode = beforeHead;
        beforeHead = *head;
        (*head) = afterHead;
    }
    *head = beforeHead;
}

// recursive
Node *ReverseLLRecurive(Node *head){
    // basecase
    if(head==NULL || head->nextNode==NULL)
    {
        printf("head->data %d\n",head->nextNode);
        return head;
    }
    Node* curr = ReverseLLRecurive(head->nextNode);
    head->nextNode->nextNode = head;
    head->nextNode = NULL;
    return curr;
}

int main(){
    Node *head = NULL;
    InsertNodeFromTail(&head,1);
    InsertNodeFromTail(&head,2);
    InsertNodeFromTail(&head,3);
    InsertNodeFromTail(&head,4);
    // InsertNodeFromTail(&head,5);
    PrintLL(head);

    // reverse linked list
    puts("\nReverseLL-------------");
    ReverseLL(&head);
    PrintLL(head);

    puts("\nReverseLL2-------------");
    ReverseLL2(&head);
    PrintLL(head);

    // recursive

    puts("\nReverseLLRecursive-------------");
    head = ReverseLLRecurive(head);
    PrintLL(head);
    return 0;
}

void PrintLL(Node *head){
    if(head==NULL) return;
    while(head != NULL){
        printf("%d -> ",head->data);
        head = head->nextNode;
    }
    puts("NULL");
}

void InsertNodeFromTail(Node **headRef, int data){
    Node *newNode = new Node();
    newNode->data = data;
    newNode->nextNode = NULL;

// this helps us to traverse the list untill we at BEFORE the end of list
    Node *traverseList = new Node();
    traverseList = *headRef;

    if((*headRef)==NULL){
        *headRef = newNode;
        return;
    }
    while(traverseList->nextNode != NULL){
        traverseList = traverseList->nextNode;
    }
    traverseList->nextNode= newNode;
    return;
}
/*
our first target is to put NULL in the link part of the first node without losing the reference of the second node. So, we need another pointer that will point to the second node of the list.

in this case we will declare "another pointer" as afterHead

the idea is to update the link part of one node at a time which is pointed by the head pointer

https://www.youtube.com/watch?v=XgABnoJLtG4&list=PLBlnK6fEyqRj9lld8sWIUNwlKfdUoPd1Y&index=56

https://www.geeksforgeeks.org/reverse-a-linked-list/

https://www.youtube.com/watch?v=MRe3UsRadKw
Reverse a Linked List Recursively

*/