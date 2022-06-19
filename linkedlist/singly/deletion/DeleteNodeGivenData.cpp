#include <iostream>
using std::cout;
using std::endl;

class Node{
public:
    int data;
    Node *nextNode;
};

void PrintLL(Node *head);
void insertNodeFromTail(Node **headRef, int data);

void DeleteNodeGivenData(Node **headReference,int key){
    // *tmp will helps us to delete the node
    Node *tmp = new Node();
    tmp = *headReference;

    // *prev will helps us to connect the missing node (node that we intend to delete)., why it called prev? because prev points to the previous node to be deleted
    Node *prev = new Node();
    prev = NULL;

    // check if list already empty then we can simply return
    if((*headReference)==NULL) return;

    // check if head node itself holds the key to be deleted and check if head is not equal to null
    if((*headReference)->data == key){
        *headReference = (*headReference)->nextNode; // head pointing to the next node
        delete tmp;
        return;
    }else{
        while((*headReference)->data != key){
            prev = tmp;
            tmp = tmp->nextNode;
        }
        // if the key was not present in linked list 
        if(tmp == NULL)
            return;
            
        // delete node if key was present in linked list
        prev->nextNode = tmp->nextNode;
        delete tmp;
    }
}

int main(){
    Node *head = NULL;
    insertNodeFromTail(&head,0);
    insertNodeFromTail(&head,1);
    insertNodeFromTail(&head,2);
    insertNodeFromTail(&head,3);
    PrintLL(head);

    // delete node
    DeleteNodeGivenData(&head, 2);

    PrintLL(head);

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

void insertNodeFromTail(Node **headRef, int data){
    Node *newNode = new Node();
    newNode->data = data;
    newNode->nextNode = NULL;

// this helps us to traverse the list untill we at BEFORE the end of list
    Node *traverseList = new Node();
    traverseList = *headRef;

    if((*headRef)==NULL){
        *headRef = newNode;
        return;
    }
    while(traverseList->nextNode != NULL){
        traverseList = traverseList->nextNode;
    }
    traverseList->nextNode= newNode;
    return;
}

/*
https://www.geeksforgeeks.org/linked-list-set-3-deleting-node/
*/