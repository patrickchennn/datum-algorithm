#include <bits/stdc++.h>
using namespace std;

class Node{
public:
    int data;
    Node* next;
};

// without return method
// https://www.youtube.com/watch?v=90zyJ1eVeUw&list=PLBlnK6fEyqRj9lld8sWIUNwlKfdUoPd1Y&index=45
void insertLinkList1(Node** headRef,int val){
    // allocate node
    Node* newNode = new Node();

    // new node points to the given data;
    newNode->data = val;

    // make the newnode points to the head node
    newNode->next = (*headRef);

    // move the head to point to the new node
    (*headRef) = newNode;
}

// with return value
Node* insertLinkList2(Node* head,int data){
    Node* newNode = new Node();
    newNode->data = data;
    newNode->next = head;
    if(head==NULL){
        printf("head==%d\n",head);
        head = newNode;
        return head;
    }
    // if(head != NULL) newNode->next = head;

    head = newNode;
    // return head;
    return head;
}

// Node* insertLinkList2(Node* head,int data){
//     Node* tmp = new Node();
//     tmp->data = data;
//     tmp->next = tmp;
//     return tmp;
// }

// print link list 
void print(Node* head);

int main(){
    // 1 way
    Node* head = NULL;
    head = new Node();
    // another way how to declare node
    // Node* head = new Node();

    /*
    head data = 0
    head next = 0
    head address:
    */
    printf("head data %d\n",head->data);
    printf("head next %p\n",head->next);
    printf("head address %p\n",head);

    int n;
    cout << "How many numbers? ";
    cin >> n;
    cout << "Enter the numbers:" << endl;
    for(int i=0; i<n; i++){
        int data;
        cin >> data;

        // without return method/pass by address
        // insertLinkList1(&head,data);
        // print(head);

        // with retrun method/pass by value
        head = insertLinkList2(head,data);
    }
    print(head);
    return 0;
}

/*
g++ InsertLLHead.cpp -o bin/InsertLLHead

5
38
48
39
97
32

3
10
20
30

Insert ll at the head


https://medium.com/swlh/javascript-inserting-a-node-at-the-head-of-a-linked-list-160b68e7abcb
https://www.hackerrank.com/challenges/insert-a-node-at-the-head-of-a-linked-list/problem
https://www.geeksforgeeks.org/linked-list-set-2-inserting-a-node/
https://www.youtube.com/watch?v=cAZ8CyDY56s&list=PL2_aWCzGMAwI3W_JlcBbtYTwiQSsOTa6P&index=6
https://www.log2base2.com/data-structures/linked-list/inserting-a-node-at-the-beginning-of-a-linked-list.html
*/

void print(Node* head){
    cout << "List is: ";
    while(head->next != NULL){
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}