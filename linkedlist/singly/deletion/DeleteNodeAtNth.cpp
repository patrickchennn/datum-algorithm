#include <iostream>
using std::cout;
using std::endl;

class Node{
public:
    int data;
    Node *next;
};

void PrintLL(Node *head);
void InsertFromTail(Node **headRef, int data);
int linkListSize(Node *head);

void DeleteNodeAtNth(Node **headRef,int position){

    // node to be deleted
    Node* deleteNode = *headRef;

    // help the PREVIOUS deleted node and connect it next AFTER the deleted node
    // Node *headPtr = *headRef;
    Node *headPtr = NULL;
    
    int size = linkListSize(*headRef);

// if linked list is empty or position is not in list
    if((*headRef)==NULL || position > size){
        printf(
            "list is already empty or position %d not exist\n"
            ,position
        );
        
        return;
    }
    else if(position == 0){
        *headRef = headPtr->next;
        
        delete deleteNode;
        return;
    }else{
        while(position != 0){
            headPtr = deleteNode;
            deleteNode = deleteNode->next;
            position--;
        }
        headPtr->next = deleteNode->next;
        delete deleteNode;
    }

}

int main(){
    Node *head = NULL;

    InsertFromTail(&head,0);
    InsertFromTail(&head,1);
    InsertFromTail(&head,2);
    InsertFromTail(&head,3);
    PrintLL(head);

    // delete ll
    // DeleteNodeAtNth(&head,9);
    DeleteNodeAtNth(&head,2);
    // DeleteNodeAtNth(&head,1);

    PrintLL(head);
    // cout << linkListSize(head) << endl;
    return 0;
}

int linkListSize(Node *head){
    int count = 0;
    while(head != NULL){
        count++;
        head = head->next;
    }
    return count;
}

void PrintLL(Node *head){
    if(head==NULL) return;
    while(head != NULL){
        printf("%d -> ",head->data);
        head = head->next;
    }
    puts("NULL");
}

void InsertFromTail(Node **headRef, int data){
    Node *newNode = new Node();
    newNode->data = data;
    newNode->next = NULL;

// this helps us to traverse the list untill we at BEFORE the end of list
    Node *traverseList = new Node();
    traverseList = *headRef;

    if((*headRef)==NULL){
        *headRef = newNode;
        return;
    }
    while(traverseList->next != NULL){
        traverseList = traverseList->next;
    }
    traverseList->next= newNode;
    return;
}

/*
https://www.youtube.com/watch?v=f1r_jxCyOl0&list=PLBlnK6fEyqRj9lld8sWIUNwlKfdUoPd1Y&index=54
Single Linked List (Deleting the Node at a Particular Position)

https://www.hackerrank.com/challenges/delete-a-node-from-a-linked-list/problem?isFullScreen=true

https://www.geeksforgeeks.org/delete-a-linked-list-node-at-a-given-position/
*/