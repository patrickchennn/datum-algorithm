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
void printLLReverse2(Node *head);
void printLL(Node *head);
void InsertNodeAtTail(Node **headReference,int inputData);

Node *reverseIterative(Node *head){
    if(head == NULL) return NULL;
    Node *curr = head;
    Node *nextCurr = head;
    Node *prevCurr = NULL;
    while(curr != NULL){
        prevCurr = curr;
        nextCurr = nextCurr->nextNode;
        curr->nextNode = curr->prevNode;
        curr->prevNode = nextCurr;
        curr = nextCurr;
    }
    head = prevCurr;
    return head;
}

Node *reverseIterative2(Node *head){
    // 2 pointers only
    if(head == NULL) return NULL;
    Node *curr = head;
    Node *newHead = NULL;
    while(curr != NULL){
        curr->prevNode = curr->nextNode; // swap previous with next
        curr->nextNode = newHead; // swap next with previous
        newHead = curr;
        curr = curr->prevNode;
    }
    return newHead;
}

Node *reverse(Node *head){
    // if list is empty, return
    if(head==NULL) return NULL;

    //otherwise, swap the next and prev
    Node *nextCurr = head->nextNode;
    head->nextNode = head->prevNode;
    head->prevNode = nextCurr;

    //if the prev is now NULL, the list has been fully reversed, and it's gonna return new head pointing at the tail of linked list
    if(head->prevNode==NULL) return head;

    // otherwise, keep going
    return reverse(head->prevNode);

    // note that when it comes to recursive solution, try to draw/visualize at paper!
}

int main(){
    Node *head = NULL;
    InsertNodeAtTail(&head,1);
    InsertNodeAtTail(&head,2);
    InsertNodeAtTail(&head,3);
    InsertNodeAtTail(&head,4);
    printLL(head);

    // head = reverse(head); // recursive
    // head = reverseIterative(head); // iterative
    head = reverseIterative2(head); // iterative2

    printLL(head);
    puts("check");
    printLLReverse2(head);
	return 0;
}

/*
https://www.hackerrank.com/challenges/reverse-a-doubly-linked-list/problem?isFullScreen=false

https://www.youtube.com/watch?v=_6JI9XdO8nM&list=PLdo5W4Nhv31bbKJzrsKfMpo_grxuLl8LU&index=19
2.13 Reverse a doubly linked list | data structures

*/

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

void printLLReverse2(Node *head){
    while(head->nextNode!=NULL)
        head = head->nextNode;

    while(head!=NULL){
        printf("%d --> ",head->data);
        head = head->prevNode;
    }
    puts("NULL");
}

void printLL(Node *head){
    while(head!=NULL){
        printf("%d --> ",head->data);
        head = head->nextNode;
    }
    puts("NULL");
}