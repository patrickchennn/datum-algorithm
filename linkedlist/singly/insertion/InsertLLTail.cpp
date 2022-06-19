#include <iostream>
using std::cout;
using std::endl;

class Node{
public:
    int data;
    Node *nextNode;
};

void PrintLL(Node *head);

void InsertNodeFromTail(Node **headReference, int data){
    Node *newNode = new Node();
    newNode->data = data;
    newNode->nextNode = NULL;

    if((*headReference)==NULL){
        *headReference = newNode;
        return;
    }
    // we need to traverse the ll untill end-1/before end, because we want to insert a new node at the end, and *traverseList will helps us to update the link
    Node *traverseList = *headReference;
    while(traverseList->nextNode != NULL){
        traverseList = traverseList->nextNode;
    }
    traverseList->nextNode= newNode;
    return;
}

int main(){
    Node *head = NULL;

    cout << head << endl;
    // call by reference
    // InsertNodeFromTail(&head,1);
    // InsertNodeFromTail(&head,2);
    // InsertNodeFromTail(&head,3);

    // PrintLL(head);
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
/*
insert 1
1 -> NULL

insert 2
1 -> 2 -> NULL

insert 3
1 -> 2 -> 3 -> NULL
*/