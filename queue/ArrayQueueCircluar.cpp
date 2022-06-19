#include <bits/stdc++.h>
using std::cout;
using std::endl;
using std::vector;
using std::cin;
using std::string;

class Queue{
private: // properties/attributes
    std::vector<int> arr;
    int front=-1,rear=-1;
public: // constructor
    Queue(int nInput){
        arr.resize(nInput);
    }
    
public: // methods
    bool isEmpty();
    void enqueue(int val);
    void dequeue();
    void top();
    void show();
};

int main(){
    Queue myQueue = Queue(4);

    myQueue.enqueue(1);
    // myQueue.printf("front(%d) rear(%d)\n",rear,front);
    myQueue.enqueue(2);
    myQueue.enqueue(3);

    myQueue.show(); // check
    myQueue.dequeue();
    myQueue.dequeue();
    myQueue.show(); // check

    myQueue.enqueue(8);
    myQueue.enqueue(9);
    myQueue.show(); // check

    // myQueue.top();

    myQueue.enqueue(10);
    // myQueue.enqueue(12);
    myQueue.show(); // check

	return 0;
}

void Queue::enqueue(int val){
    if((rear+1)%arr.size() == front){
        puts("Queue is full!!!");
        return;
    }
    else if(isEmpty()){
        printf("%d is the first number in queue!\n",val);
        rear = front = 0;
        arr[rear] = val;
    }else{
        printf("%d pushed into queue!\n",val);
        rear = (rear+1)%arr.size(); // increment rear
        arr[rear] = val;
    }

}

void Queue::dequeue(){
    if(front==rear)
        front = rear = -1;
    else if(isEmpty()){
        puts("There's no number in this queue!");
        return;
    }
    else{
        printf("Popped \"%d\" from the queue!\n",arr[front]);
        arr[front] = 0;
        front = (front+1)%arr.size(); // increment front
        // printf("front %d \n",front);
    }       
}

bool Queue::isEmpty(){
    if(front==-1 && rear==-1)
        return true;
    return false;
}

void Queue::top(){
    cout << "Front value: " << arr[front] << endl;
}

void Queue::show(){
    for(int i=0; i<arr.size(); i++)
        cout << arr[i] << " ";
    cout << endl;
}

/*
https://www.youtube.com/watch?v=okr-XE8yTO8&list=PL2_aWCzGMAwI3W_JlcBbtYTwiQSsOTa6P&index=23
Data structures: Array implementation of Queue

*/