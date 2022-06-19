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
void printLLReverse(Node *head);

int main(){
    Node *head = NULL;
    Node *second = NULL;
    Node *tail = NULL;

    head = new Node();
    second = new Node();
    tail = new Node();

    printf("head address: %p\n",head);
    printf("second node address: %p\n",second);
    printf("tail node address: %p\n\n",tail);
    head->prevNode = NULL;
    head->data = 1;
    head->nextNode = second;

    
    printf("%p <-- %d --> %p\n",head->prevNode,head->data,head->nextNode);

    second->prevNode = head;
    second->data = 2;
    second->nextNode = tail;
    printf("%p <-- %d --> %p\n",second->prevNode,second->data,second->nextNode);

    tail->prevNode = second;
    tail->data = 3;
    tail->nextNode = NULL;
    printf("%p <-- %d --> %p\n",tail->prevNode,tail->data,tail->nextNode);

    puts("---------------");
    printLL(head);

    // printLLReverse(tail);

    printLLReverse2(head);

	return 0;
}

void printLL(Node *head){
    while(head!=NULL){
        printf("%d --> ",head->data);
        head = head->nextNode;
    }
    puts("NULL");
}

void printLLReverse2(Node *head){
    while(head->nextNode!=NULL)
        head = head->nextNode;

    while(head!=NULL){
        printf("%d --> ",head->data);
        head = head->prevNode;
    }
    puts("NULL");
    // this will helps to check if there is any broken link
}

void printLLReverse(Node *tail){
    while(tail!=NULL){
        printf("%d --> ",tail->data);
        tail = tail->prevNode;
    }
    puts("NULL");
}

/*
https://www.youtube.com/watch?v=nquQ_fYGGA4&list=PLdo5W4Nhv31bbKJzrsKfMpo_grxuLl8LU&index=15
2.9 Introduction to Doubly Linked List - Data structures

*/