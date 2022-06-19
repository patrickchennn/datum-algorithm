#include <bits/stdc++.h>
using std::cout;
using std::endl;
using std::vector;
using std::cin;

class Node{
public:
    int data;
    Node *nextNode;
};

void push(Node **top,int data);
void pop(Node **top);
void peek(Node *top);
void display(Node *top);
bool isEmpty(Node *top);

int main(){
    Node *top = NULL;
    push(&top,1);
    push(&top,2);
    push(&top,3);

    display(top);

    pop(&top);
    display(top);

    peek(top);
    // cout << std::boolalpha << isEmpty(top) << endl;
	return 0;
}

void peek(Node *top){
    printf("Top element is %d\n", top->data);
}

bool isEmpty(Node *top){
    return (top==NULL) ? true : false;
    // return (!(top)) ? true : false;

    // same. Either works!
}

void pop(Node **top){
    if(!(*top)){
        puts("There is nothing to delete!");
        return;
    }
    Node *tmp = *top;
    *top = (*top)->nextNode;
    delete tmp;
}

void display(Node *top){
    while(top != NULL){
        printf("%d -> ",top->data);
        top = top->nextNode;
    }
    puts("NULL");
}

void push(Node **top,int inputData){
    Node *newNode = new Node();
    newNode->data = inputData;
    if(!(*top)){
        newNode->nextNode = NULL;
        *top = newNode;
        return;
    }
    newNode->nextNode = *top;
    *top = newNode;
}

/*
https://www.youtube.com/watch?v=MuwxQ2IB8lQ&list=PL2_aWCzGMAwI3W_JlcBbtYTwiQSsOTa6P&index=16

https://www.geeksforgeeks.org/implement-a-stack-using-singly-linked-list/
*/