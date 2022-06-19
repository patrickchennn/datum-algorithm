#include <bits/stdc++.h>
using std::cout;
using std::endl;
using std::vector;
using std::cin;
using std::string;

class Node{
public:
    int data;
    Node *nextNode;
};

void printLL(Node *head);
void InsertNodeAtTail(Node **headReference,int inputData);

void revLL(Node **headReference){
    std::stack<Node *> S;
    Node *temp = *headReference;
    while(temp != NULL){
        S.push(temp);
        temp = temp->nextNode;
    }

    temp = S.top();
    *headReference = temp;
    S.pop();
    while(!(S.empty())){
        temp->nextNode = S.top();
        S.pop();
        temp = temp->nextNode;
    }
    temp->nextNode = NULL;
}

int main(){
    Node *head = NULL;
    InsertNodeAtTail(&head,1);
    InsertNodeAtTail(&head,2);
    InsertNodeAtTail(&head,3);
    InsertNodeAtTail(&head,4);

    printLL(head);
    revLL(&head);
    printLL(head);

	return 0;
}

/*
https://www.youtube.com/watch?v=hNP72JdOIgY&list=PL2_aWCzGMAwI3W_JlcBbtYTwiQSsOTa6P&index=17
*/



void printLL(Node *head){
    while(head != NULL){
        printf("%d -> ",head->data);
        head = head->nextNode;
    }
    puts("NULL");
}

void InsertNodeAtTail(Node **headReference,int inputData){
    Node *newNode = new Node();
    newNode->data = inputData;
    newNode->nextNode = NULL;
    if(!(*headReference)){
        *headReference= newNode;
        return;
    }
    Node *traverse = *headReference;
    while(traverse->nextNode != NULL)
        traverse = traverse->nextNode;
    newNode->nextNode = traverse->nextNode;
    traverse->nextNode = newNode;
}