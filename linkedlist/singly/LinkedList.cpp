#include <bits/stdc++.h>
using namespace std;

class Node{
public:
    int data;
    Node* next;
};  
/*
pictorially (Node is a cointainer basically)
------------------
| data | pointer |
------------------
*/

void printLinkList(Node* head){
    while(head != NULL){
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

void countNode(Node* head){
    int sum=0;
    if(head==0){
        cout << "Linked List is empty" << endl;
        return;
    }
    while(head != NULL){
        sum++;
        head = head->next;
    }
    cout << sum << endl;
}

int main(){
    Node* head = NULL;
    Node* second = NULL;
    Node* third = NULL;

    head = new Node();
    second = new Node();
    third = new Node();

    head->data = 2;
    head->next = second;

    second->data = 4;
    second->next = third;

    third->data = 6;
    third->next = NULL;

    cout << head->data << endl;
    cout << head->next->data << endl;
    cout << head->next->next->data << endl;
    cout << third->data << endl << endl;

    printLinkList(head);
    countNode(head);
    // test(head);
    return 0;
}
/*
https://www.geeksforgeeks.org/linked-list-set-1-introduction/

https://www.youtube.com/watch?v=hEl8FythuoY&list=PLhb7SOmGNUc5AZurO-im4t_RDr-ymjz0d&index=5

*/
