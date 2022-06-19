#include <bits/stdc++.h>
using namespace std;

class Node{
public:
    int data;
    Node* nextNode;
};
void InsertNodeAtTail(Node** head,int inputData);
void printLL(Node *head);

void insertPos(Node** head,int pos,int inputData){
    Node* newNode = new Node();
    newNode->data = inputData;
    if(pos == 0){
        newNode->nextNode = *head;
        *head = newNode;
        return;
    }
    newNode->nextNode = NULL;

    // Node* traverse will helps us to traverse the list untill at index list
    Node* traverse = *head;
    while(--pos){
    // while(pos != 1){
        traverse = traverse->nextNode;
        // pos--;
    }
    newNode->nextNode = traverse->nextNode;
    traverse->nextNode = newNode;
}

int main(){
    Node* head = NULL;

    //insert a data to node
    InsertNodeAtTail(&head,16);
    InsertNodeAtTail(&head,13);
    InsertNodeAtTail(&head,7);

    printLL(head);

    // void insertPos(Node** head,int pos,int inputData)

    // insert node at the n-th/given position
    insertPos(&head,0,12213);
    insertPos(&head,2,1);

    // printLL(head);
    // insertPos(&head,4,123);
    // printLL(head);
    printLL(head);


    return 0;
}

void printLL(Node* head){
    while(head != NULL){
        printf("%d -> ",head->data);
        head = head->nextNode;
    }
    cout << "NULL"<< endl;
}

/*
NOTE THAT the list start from 0 index

g++ InsertLLAtNth.cpp -o bin/InsertLLAtNth

https://www.geeksforgeeks.org/insert-a-node-at-a-specific-position-in-a-linked-list/


https://www.youtube.com/watch?v=0hGxILnKvJk


https://www.hackerrank.com/challenges/insert-a-node-at-a-specific-position-in-a-linked-list/problem


https://www.youtube.com/watch?v=IbvsNF22Ud0&list=PL2_aWCzGMAwI3W_JlcBbtYTwiQSsOTa6P&index=7


*/

void InsertNodeAtTail(Node** head,int inputData){
    Node* newNode = new Node();
    Node* current = *head;
    newNode->data = inputData;
    newNode->nextNode = NULL;
    if(*head == NULL){
        (*head) = newNode;
        return;
    }
    while(current->nextNode != NULL)
        current = current->nextNode;

    current->nextNode = newNode;
    return;
}