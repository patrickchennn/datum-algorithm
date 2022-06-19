#include <iostream>
using std::cout;
using std::endl;

class Node{
public:
    int data;
    Node *nextNode;
};

void insertNodeAtTail(Node **head,int data);
void printLL(Node *head);

void deleteFirstNode(Node **head){
    Node *tmp = *head;
    if(*head == NULL) return;
    // *head = headPtr->nextNode;
    *head = (*head)->nextNode;

    delete tmp;

    // C-style
    // free(headPtr);
    // headPtr = NULL;
}

int main(){
    Node *head = NULL;

    // pass by address
    insertNodeAtTail(&head,9);
    insertNodeAtTail(&head,10);
    insertNodeAtTail(&head,1121);

    printLL(head);

    deleteFirstNode(&head);
    deleteFirstNode(&head);


    printLL(head);

    return 0;
}

void printLL(Node *head){
    if(head==NULL) return;
    while(head!=NULL){
        printf("%d -> ",head->data);
        head = head->nextNode;
    }
    puts("NULL");
}

void insertNodeAtTail(Node **head,int data){
    Node *newNode = new Node();
    newNode->data = data;
    newNode->nextNode = NULL;

    Node *traverseList = new Node();
    traverseList = *head;

    if(*head == NULL){
        cout << "if" << endl;
        (*head) = newNode;
        return;
    }
    while(traverseList->nextNode != NULL){
        cout << "while" << endl;
        traverseList = traverseList->nextNode;
    }
    traverseList->nextNode = newNode;
}

/*
https://www.youtube.com/watch?v=-rcIWx-JTxw&list=PLBlnK6fEyqRj9lld8sWIUNwlKfdUoPd1Y&index=49
Single Linked List (Deleting the First Node)

*/
