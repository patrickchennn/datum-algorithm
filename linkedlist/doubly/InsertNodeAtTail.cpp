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

int main(){
    Node *head = NULL;
    InsertNodeAtTail(&head,1);
    InsertNodeAtTail(&head,2);
    InsertNodeAtTail(&head,3);

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
