#include <bits/stdc++.h>
using namespace std;

class Node{
public:
    int data;
    Node* next;
};

void insertNodeAtTail(Node** head,int val);
void printLL(Node* head);

void deleteNodeAtNth(Node** head,int position){
    // if list is empty then return
    if(head==NULL) return;

    Node* headPtr = *head;

    // if head needs to be removed
    if(position==0){
        *head = headPtr->next; // change head
        free(headPtr);          // free old head
        return;
    }

    for(int i=0; headPtr != NULL && i<position-1; i++)
        headPtr = headPtr->next;

    // if pos is more than number of nodes
    if(headPtr == NULL || headPtr->next == NULL) return;

    Node* nextPostition = headPtr->next->next;
    free(headPtr->next);
    headPtr->next = nextPostition;
    headPtr = NULL;
}

void deleteHeadNode(Node** head){
    if(head==NULL){
        puts("List is already empty");
        return;
    }
    Node* headPtr = *head;
    *head = headPtr->next;
    free(headPtr);
    headPtr = NULL;
}

void deleteHeadNode2(Node** head){
    // another version how to delete node at the head
    if(*head==NULL){
        puts("List is already empty");
        return;
    }else if((*head)->next==NULL){
        free(head);
        head=NULL;
    }else{
        Node* last = *head;
        while(last->next->next != NULL){
            last = last->next;
        }
        free(last->next);
        last->next = NULL;
    }
}

void deleteTailNode(Node** head){
    if(*head==NULL){
        puts("List is already empty");
        return;
    }else if((*head)->next==NULL){
        free(head);
        head=NULL;
    }else{
        Node* deleteNode = *head;
        Node* ptrToNull = *head;

        while(deleteNode->next != NULL){
            ptrToNull = deleteNode;
            deleteNode = deleteNode->next;
        }
        ptrToNull->next=NULL;
        free(deleteNode);
        deleteNode=NULL;
    }
}

void deleteEntireNode(Node** head){
    Node* traverse = *head; 
    while(traverse!=NULL){
        traverse=traverse->next;
        free(*head);
        *head = traverse;
    }
}


int main(){
    Node* head = NULL;
    insertNodeAtTail(&head,0);
    insertNodeAtTail(&head,1);
    insertNodeAtTail(&head,2);
    insertNodeAtTail(&head,3);
    insertNodeAtTail(&head,4);
    insertNodeAtTail(&head,5);
    printLL(head);

    deleteNodeAtNth(&head,2);
    printLL(head);

    puts("delete head node");
    deleteHeadNode(&head);
    printLL(head);

    deleteTailNode(&head);
    printLL(head);

    // deleteHeadNode2(&head);
    // printLL(head);

    deleteEntireNode(&head);
    printLL(head);

    return 0;
}
void printLL(Node* head){
    if(head==NULL){
        puts("List is empty");
        return;
    }
    while(head != NULL){
        printf("%d -> ",head->data);
        head = head->next;
    }
    puts("NULL");
}

void insertNodeAtTail(Node** head,int val){
    Node* newNode = new Node();
    Node* ptrHead = *head;
    newNode->data = val;
    newNode->next = NULL;
    if(*head==NULL){
        *head = newNode;
        return;
    }
    while(ptrHead->next != NULL)
        ptrHead = ptrHead->next;

    ptrHead->next = newNode;
    return;
}


/*
g++ DeleteNode.cpp -o bin/DeleteNode

https://www.geeksforgeeks.org/linked-list-set-3-deleting-node/
https://www.geeksforgeeks.org/delete-a-linked-list-node-at-a-given-position/
https://www.hackerrank.com/challenges/delete-a-node-from-a-linked-list/problem
*/