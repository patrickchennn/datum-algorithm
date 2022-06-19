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
    bool isFull();
    void enqueue(int val);
    void dequeue();
    void top();
    void showAll();
    void show();
};

int main(){
    Queue myQueue = Queue(4);

    myQueue.enqueue(1);
    // myQueue.printf("front(%d) rear(%d)\n",rear,front);
    myQueue.enqueue(2);
    myQueue.enqueue(3);

    myQueue.show(); // print untill last data

    myQueue.showAll(); // print all
    myQueue.dequeue();
    myQueue.dequeue();
    myQueue.showAll(); // check

    myQueue.enqueue(8);
    myQueue.enqueue(9); // we can't insert data anymore cause array already full
    myQueue.showAll(); // check

    myQueue.top();


	return 0;
}

void Queue::show(){
    cout << "Array: ";
    for(int i=0; i<rear+1; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

bool Queue::isEmpty(){
    if(front==-1 && rear==-1)
        return true;
    return false;
}

bool Queue::isFull(){
    if(rear == arr.size()-1)
        return true;
    return false;
}

void Queue::enqueue(int val){
    if(isFull()){
        puts("Queue is full!!!");
        return;
    }
    else if(isEmpty()){
        printf("%d is the first number in queue!\n",val);
        rear = front = 0;
        arr[rear] = val;
    }else{
        printf("%d pushed into queue!\n",val);
        rear++;
        arr[rear] = val;
        // printf("rear = %d\n",rear);
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
        arr[front] = 0; // delete the data, although it's not necessary
        front++;
    }       
}

void Queue::top(){
    cout << "Front value: " << arr[front] << endl;
}

void Queue::showAll(){
    for(int i=0; i<arr.size(); i++)
        cout << arr[i] << " ";
    cout << endl;
}


/*
https://www.youtube.com/watch?v=okr-XE8yTO8&list=PL2_aWCzGMAwI3W_JlcBbtYTwiQSsOTa6P&index=23
Data structures: Array implementation of Queue


https://www.youtube.com/watch?v=YqrFeU90Coo&list=PLdo5W4Nhv31bbKJzrsKfMpo_grxuLl8LU&index=42
4.2 Implementation of queue using Arrays | data structures


https://www.geeksforgeeks.org/queue-set-1introduction-and-array-implementation/
*/