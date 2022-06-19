#include <bits/stdc++.h>
using std::cout;
using std::endl;
using std::vector;
using std::cin;

class Node{
public:    
    Node *prevNode;
    int data;
    Node *nextNode;
};
void printLL(Node *head);
void InsertNodeAtTail(Node **headReference,int inputData);

void InsertNodeAtPos(Node **headReference,int inputData,int pos){
    Node *newNode = new Node();
    newNode->prevNode = NULL;
    newNode->data = inputData;
    if(pos==0){
        newNode->nextNode = *headReference;
        *headReference = newNode;
        return;
    }

    newNode->nextNode = NULL;

    Node *traverse = *headReference;
    
    while(--pos){
        traverse = traverse->nextNode;
    }
    newNode->prevNode = traverse;
    newNode->nextNode = traverse->nextNode;
    traverse->nextNode = newNode;
    // cout << "expect val 3 = " << traverse->data << endl;
}

int main(){
    Node *head = NULL;
    InsertNodeAtTail(&head,1);
    InsertNodeAtTail(&head,2);
    InsertNodeAtTail(&head,3);
    InsertNodeAtTail(&head,4);


    printLL(head);
    puts("-----------------------");
    InsertNodeAtPos(&head,99,3);
    printLL(head);

    InsertNodeAtPos(&head,9123,0);
    printLL(head);

}

/*
https://www.geeksforgeeks.org/doubly-linked-list/
*/

void printLL(Node *head){
    if(head==NULL){
        puts("List is empty!");
        return;
    }
    
    while(head!=NULL){
        printf("%d --> ",head->data);
        head = head->nextNode;
    }
    puts("NULL");
}

void InsertNodeAtTail(Node **headReference,int inputData){
    Node *newNode = new Node();
    newNode->prevNode = NULL;
    newNode->data = inputData;
    newNode->nextNode = NULL;
    
    if((*headReference) == NULL){
        *headReference = newNode;
        return;
    }
    // ptr to traverse the list untill it reachs before at the end of list
    Node *traverse = *headReference;
    while(traverse->nextNode != NULL){
        traverse = traverse->nextNode;
    }
    newNode->prevNode = traverse;
    traverse->nextNode = newNode;
    return;
}