#include <bits/stdc++.h>
using std::cout;
using std::endl;
using std::vector;
using std::cin;

class Node{
public:
    int data;
    Node *nextNode;
};

void PrintLL(Node *head);

void printLLC(Node *head){
    Node *curr = head;
    while(curr->nextNode != head){
        printf("%d -> ",curr->data);
        curr = curr->nextNode;
    }
    printf("%d -> ",curr->data);
    printf("%d -> ... \n",curr->nextNode->data);
}

void makeCircular(Node **head){
    Node *curr = *head;
    while(curr->nextNode != NULL)
        curr = curr->nextNode;
    curr->nextNode = *head;
}

void InsertNodeAtTail(Node **head,int inputData){
    Node *newNode = new Node();
    newNode->data = inputData;
    newNode->nextNode = NULL;
    if((*head)==NULL){
        *head = newNode;
        return;
    }
    // *curr to traverse untill it reaches before at the end of the list
    Node *curr = *head;
    while(curr->nextNode != NULL)
        curr = curr->nextNode;
    curr->nextNode = newNode;
}

bool detectCycle(Node *head){
    Node *hare = head, *tortoise = head;

    while(tortoise != NULL && tortoise->nextNode != NULL){
        tortoise = tortoise->nextNode->nextNode;
        hare = hare->nextNode;
        if(tortoise==hare)
            return true;
    }
    return false;
}

int main(){
    Node *head = NULL;

    InsertNodeAtTail(&head,1);
    printf("head node address = %p\n",head);

    InsertNodeAtTail(&head,2);
    InsertNodeAtTail(&head,3);

    // PrintLL(head);

    // make tail node points to head node
    makeCircular(&head);

    // check if tail points to head, if it true, then our circular linked list worked!
    cout << std::boolalpha << detectCycle(head) << endl;
    printLLC(head);

	return 0;
}

/*

https://www.youtube.com/watch?v=fmfx1C4TTxw&list=PLdo5W4Nhv31bbKJzrsKfMpo_grxuLl8LU&index=20
2.14 Circular linked list in data structure - Creation and display

*/

void PrintLL(Node *head){
    if(head==NULL) return;
    while(head != NULL){
        printf("%d -> ",head->data);
        head = head->nextNode;
    }
    puts("NULL");
}