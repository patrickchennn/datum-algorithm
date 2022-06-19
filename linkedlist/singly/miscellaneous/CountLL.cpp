#include <iostream>
using std::cout;
using std::endl;

class Node{
public:
    int data;
    Node *nextNode;
};

void PrintLL(Node *head);
void InsertFromTail(Node **headRef, int data);

int recursive(Node *head){
    if(head == NULL)
        return 0;

    return 1+recursive(head->nextNode);
}

int count=0;
int recursive2(Node *head){
    if(head == NULL)
        return 0;
    count++;
    return count = recursive2(head->nextNode);
}

int iterative(Node *head){
    int count=0;
    while(head != NULL){
        ++count;
        head = head->nextNode;
    }
    return count;
}

int main(){
    Node *head = NULL;

    InsertFromTail(&head,0);
    InsertFromTail(&head,1);
    InsertFromTail(&head,2);
    InsertFromTail(&head,3);
    PrintLL(head);

    cout << recursive2(head) << endl;
    cout << iterative(head) << endl;

    return 0;
}

void PrintLL(Node *head){
    if(head==NULL) return;
    while(head != NULL){
        printf("%d -> ",head->data);
        head = head->nextNode;
    }
    puts("NULL");
}

void InsertFromTail(Node **headRef, int data){
    Node *newNode = new Node();
    newNode->data = data;
    newNode->nextNode = NULL;

// this helps us to traverse the list untill we at BEFORE the end of list

    if((*headRef)==NULL){
        *headRef = newNode;
        return;
    }
    
    Node *traverseList = *headRef;
    while(traverseList->nextNode != NULL){
        traverseList = traverseList->nextNode;
    }
    traverseList->nextNode= newNode;
    return;
}

/*

https://www.geeksforgeeks.org/find-length-of-a-linked-list-iterative-and-recursive/
*/