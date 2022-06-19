#include <bits/stdc++.h>
using namespace std;

class Node{
public:
    int data;
    Node* next;
};

void insertTail(Node** head,int data){
    Node* newNode = new Node();
    newNode->data = data;
    newNode->next = NULL;
    
    Node* current = *head;

    if(*head == NULL){
        (*head) = newNode;
        cout << "hmm" << endl;
        return;
    }
    while(current->next != NULL)
        current = current->next;

    current->next = newNode;
    return;
}

Node *insertTail2(Node *head, int data){
    Node *newNode = new Node();
    newNode->data = data;
    newNode->next = NULL;

    Node *traveseList = head;
    if(head==NULL || head->data==0){
        printf("head == %d\n",head);
        head = newNode;
        return head;
    }

    while(traveseList->next != NULL)
        traveseList = traveseList->next;
    traveseList->next = newNode;
    return head;
}

void print(Node* head){
    cout << "List is: ";
    while(head != NULL){
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

int main(){
    Node* head = NULL;
    // head = new Node();
    // printf("head data %d\n",head->data);
    // printf("head next %p\n",head->next);
    printf("head address %p\n",head);
    
    cout << "Enter how many numbers? ";
    int n; cin >> n;
    for(int i=0; i<n; i++){
        int data;
        cin >> data;
        // insertTail(&head,data);

        // using return
        head = insertTail2(head,data);
    }
    print(head);
    return 0;
}
/*
g++ InsertLLTail.cpp -o bin/InsertLLTail

https://www.log2base2.com/data-structures/linked-list/inserting-a-node-at-the-end-of-a-linked-list.html
https://medium.com/swlh/javascript-inserting-a-node-at-the-tail-of-a-linked-list-4eb742fb1a23
https://www.youtube.com/watch?v=LYGbeWnYXd8&list=PLBlnK6fEyqRj9lld8sWIUNwlKfdUoPd1Y&index=39
https://www.hackerrank.com/challenges/insert-a-node-at-the-tail-of-a-linked-list/problem
*/

/* NOTE THAT:
in this case we are asking user to input a certain value. So, we can't declare "head = new Node();" if we declare it, the head data will equals 0, which 0 is not a input from the user right?

head node
+---+-----+
| 0 | NULL|
+---+-----+

Or if you want to declare it, then to get rid of 0 data is by checking: if(head->data==0):head = newNode;
*/