#include <iostream>
using std::cout;
using std::endl;

class Node{
public:
    int data;
    Node *nextNode;
};

void PrintLL(Node *head);
void InsertFromTail(Node **headReference, int data);

void DeleteEntireLL(Node **headReference){
    if((*headReference) == NULL) return;
    Node *headPtr = new Node();
    headPtr = *headReference;

    while(headPtr != NULL){
        headPtr = (*headReference)->nextNode;
        free(*headReference);
        *headReference = headPtr;
    }
    printf("headPtr = %p\n",headPtr);
    printf("*headReference = %p\n",*headReference);
    return;
}

int main(){
    Node *head = NULL;

    InsertFromTail(&head,0);
    InsertFromTail(&head,1);
    InsertFromTail(&head,2);
    InsertFromTail(&head,3);
    PrintLL(head);

    // pass by address
    DeleteEntireLL(&head);

    // check if list already deleted or not
    if(head == NULL)
        printf("list = %p\n",head);
    else
        puts("list Not yet empty");

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

void InsertFromTail(Node **headReference, int data){
    Node *newNode = new Node();
    newNode->data = data;
    newNode->nextNode = NULL;

// this helps us to traverse the list untill we at BEFORE the end of list
    Node *traverseList = new Node();
    traverseList = *headReference;

    if((*headReference)==NULL){
        *headReference = newNode;
        return;
    }
    while(traverseList->nextNode != NULL){
        traverseList = traverseList->nextNode;
    }
    traverseList->nextNode= newNode;
    return;
}

/*
https://www.youtube.com/watch?v=f1r_jxCyOl0&list=PLBlnK6fEyqRj9lld8sWIUNwlKfdUoPd1Y&index=54
Deleting the Entire Single Linked List

https://www.geeksforgeeks.org/write-a-function-to-delete-a-linked-list/
*/