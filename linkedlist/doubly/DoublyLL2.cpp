#include <bits/stdc++.h>
using std::cout;
using std::endl;
using std::vector;
using std::cin;

class Node{
public:    
    Node *prevNode;
    int data;
    Node *nextNode;
};
int main(){
    Node *head = NULL;
    Node *second = NULL;
    Node *tail = NULL;

    head = new Node();
    second = new Node();
    tail = new Node();

    printf("head address: %p\n",head);
    printf("second node address: %p\n",second);
    printf("tail node address: %p\n\n",tail);
    head->prevNode = NULL;
    head->data = 1;
    head->nextNode = second;

    
    printf("%p <-- %d --> %p\n",
    head->prevNode,
    head->data,
    head->nextNode
    );

    second->prevNode = head;
    second->data = 2;
    second->nextNode = tail;
    printf("%p <-- %d --> %p\n",
    second->prevNode,
    second->data,
    second->nextNode);

    tail->prevNode = second;
    tail->data = 3;
    tail->nextNode = NULL;
    printf("%p <-- %d --> %p\n",
    tail->prevNode,
    tail->data,
    tail->nextNode);

    puts("---------------");
    cout << tail->data << endl;
    cout << tail->prevNode->data << endl;
    cout << tail->prevNode->prevNode->data << endl;
	return 0;
}

/*

*/