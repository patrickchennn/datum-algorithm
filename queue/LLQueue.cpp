#include <bits/stdc++.h>
using std::cout;
using std::endl;
using std::vector;
using std::cin;
using std::string;

class QNode{
public:
    int data;
    QNode *nextQNode;
public:// constructor
    QNode(int inputData){
        data = inputData;
        nextQNode = NULL;
    }
};

class Queue{
private:
    QNode *front = NULL;
    QNode *rear = NULL;
public: // methods

    // this enqueue function is the same as how you insert a node at the end of the linked list
    void enqueue(int inputData);

    void show();

    // this dequeue function is the same as how you delete a node at front
    void dequeue();

    void peek();

};

int main(){
    Queue myQueue = Queue();
    myQueue.enqueue(1);
    myQueue.enqueue(2);
    myQueue.enqueue(3);
    myQueue.show();

    myQueue.dequeue();
    myQueue.dequeue();
    myQueue.show();

    myQueue.enqueue(9);
    // myQueue.enqueue(10);
    myQueue.show();

    myQueue.peek();
	return 0;
}

void Queue::enqueue(int inputData){
    QNode *newQNode = new QNode(inputData);

    // if queue is empty
    if(!(front) && !(rear)){
    // if(front==NULL && rear==NULL){
        front = rear =  newQNode;
        return;
    }

    // if queue is not empty
    rear->nextQNode = newQNode;
    rear = rear->nextQNode;
}

void Queue::show(){
    QNode *head = front;
    while(head!=NULL){
        printf("%d -> ",head->data);
        head = head->nextQNode;
    }
    puts("NULL");
}

void Queue::dequeue(){
    if(front == NULL){
        puts("Nothing to delete!");
        return;
    }
    QNode *temp = front;
    front = front->nextQNode;

    if(front == NULL)
        rear = front = NULL;

    delete temp;
}

void Queue::peek(){
    if(front==NULL){
        puts("Nothing is in the queue!");
        return;
    }
    printf("Front: %d\n", front->data);
}

/*
https://www.youtube.com/watch?v=RN1wzY_tnYU&list=PLdo5W4Nhv31bbKJzrsKfMpo_grxuLl8LU&index=43
4.3 Queue implementation using linked list | data structure


https://www.geeksforgeeks.org/queue-linked-list-implementation/
*/