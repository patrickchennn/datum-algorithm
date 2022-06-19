#include <iostream>
using std::cout;
using std::endl;

class Node{
public:
    int data;
    Node *nextNode;
};

// Given a reference (pointer to pointer)
// to the head of a list and an int,
// inserts a new node on the front of the list.
void InsertFromHead(Node **headRef,int data){
    Node *newNode = new Node();
    newNode->data = data;

    // assign head with new node if head is equals null
    if(!(*headRef)){
    // if((*headRef)==NULL){
        newNode->nextNode = NULL;
        puts("*headRef==NULL block code are executed");
        *headRef = newNode;
        return;
    }
    puts("below block code are executed");
    newNode->nextNode = *headRef;
    (*headRef) = newNode;    
}

// 4 line code
void InsertFromHead2(Node** headRef,int data){
    // allocate node
    Node* newNode = new Node();

    // new node points to the given data;
    newNode->data = data;

    // make the newnode points to the head node
    newNode->nextNode = (*headRef);

    // move the head to point to the new node
    (*headRef) = newNode;
}

void PrintLL(Node *head);

int main(){
    Node *head = NULL;


    InsertFromHead(&head,1);
    InsertFromHead(&head,2);
    InsertFromHead(&head,3);

    PrintLL(head);

    
    // InsertFromHead2(&head,1);
    // cout << head->data << endl;
    // cout << head->nextNode->nextNode << endl;

    // InsertFromHead(&head,1);
    // cout << head->data << endl;
    // cout << head->nextNode << endl;

    /*
    the differences between InsertFromHead() & InsertFromHead2()
    if we pass head such that head equals null to InsertFromHead(), then it will create a proper node. what do I means by proper node? I think it node that contains a data also nextNode pointing to "NULL".


    in InsertFromHead2() case nexNode will not pointing to "NULL" it will pointing arbitrary value

    ie; InsertFromHead() it just checks if head == null then set head with newHead. newHead contains a given data by the user and null nextNode. On the other hand, InsertFromHead2() does not checks head.

    anyway I prefer InsertFromHead(), because I think it's just a good habit to check if the head == null or not
    */
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
2 -> 1 -> NULL

inesrt 3
3 -> 2 -> 1 -> NULL
*/