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

void InsertNodeAtHead(Node **headReference,int inputData){
    Node *newNode = new Node();
    newNode->prevNode = NULL;
    newNode->data = inputData;
    newNode->nextNode = *headReference;
    
    if((*headReference)==NULL){
        newNode->nextNode = NULL;
        *headReference = newNode;
        return;
    }
    (*headReference)->prevNode = newNode;
    *headReference = newNode;
    return;
}

int main(){
    Node *head = NULL;
    InsertNodeAtHead(&head,1);
    InsertNodeAtHead(&head,2);
    InsertNodeAtHead(&head,3);

    cout << head->data << endl;
    cout << head->nextNode->data << endl;
    printLL(head);
}

/*
https://www.geeksforgeeks.org/doubly-linked-list/
*/

void printLL(Node *head){
    while(head!=NULL){
        printf("%d --> ",head->data);
        head = head->nextNode;
    }
    puts("NULL");
}