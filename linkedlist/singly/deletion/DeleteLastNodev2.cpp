#include <iostream>
using std::cout;
using std::endl;

class Node{
public:
    int data;
    Node *next;
};

void printLL(Node *head);
void insertNodeAtTail(Node **head,int val);

void DeleteLastNode(Node **head){
    if(*head == NULL) return;
    else if((*head)->next == NULL){
        free(*head);
        *head = NULL;
        return;
    }else{
        Node *deleteNode = new Node();
        deleteNode = *head;
        while(deleteNode->next->next != NULL){
            deleteNode = deleteNode->next;
        }
        free(deleteNode->next);
        deleteNode->next = NULL;
    }
}


int main(){
    Node *head = NULL;
    insertNodeAtTail(&head,10);
    insertNodeAtTail(&head,15);
    insertNodeAtTail(&head,20);

    printLL(head);


    DeleteLastNode(&head);
    printLL(head);
    return 0;
}

void printLL(Node *head){
    if(head==NULL) return;
    while(head!=NULL){
        printf("%d -> ",head->data);
        head = head->next;
    }
    puts("NULL");
}

void insertNodeAtTail(Node **head,int data){
    Node *newNode = new Node();
    newNode->data = data;
    newNode->next = NULL;

    Node *traverseList = new Node();
    traverseList = *head;

    if(*head == NULL){
        // cout << "if" << endl;
        (*head) = newNode;
        return;
    }
    while(traverseList->next != NULL){
        // cout << "while" << endl;
        traverseList = traverseList->next;
    }
    traverseList->next = newNode;
}
/*

g++ DeleteLastNodev2.cpp -o bin/DeleteLastNodev2

https://www.youtube.com/watch?v=8flOSiGsO-g&list=PLBlnK6fEyqRj9lld8sWIUNwlKfdUoPd1Y&index=51
Single Linked List (Deleting the Last Node using Single Pointer)
*/