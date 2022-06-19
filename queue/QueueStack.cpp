#include <bits/stdc++.h>
using namespace std;

class Queue{
public:
    vector<int> stack1;
    vector<int> stack2;

    stack<int> s1,s2;

    void enqueue(int inputData){
        s1.push(inputData);
        stack1.push_back(inputData);
    }
    
    int dequeue(){
        // if both stacks are empty, meaning we didn't insert any value into our queue
        if(s1.empty()){
            cout << "Queue is empty!" << endl;
            exit(0);
        }

        if(s2.empty()){
            // while stack 1 is not empty, then moves all elements in s1 into s2
            // s1 = 1 2 3
            // s2 = 3 2 1
            while(!(s1.empty())){
                s2.push(s1.top());
                stack2.push_back(s1.top());
                s1.pop();
            }
        }
        // return the top item from s2 or ie it's our "front value" which we want to pop/dequeue
        int topStack2 = s2.top();
        s2.pop();
        return topStack2;
    }
    void show1(){
        cout << "stack1: [ ";
        for(auto &num : stack1)
            cout << num << " ";
        cout << ']' << endl;
    }

    void show2(){
        cout << "stack2: [ ";
        for(auto &num : stack2)
            cout << num << " ";
        cout << ']' << endl;
    }

};

int main(){
    Queue myQueue = Queue();
    myQueue.enqueue(1);
    myQueue.enqueue(2);
    myQueue.enqueue(3);
    myQueue.show1();
    //expect 1
    printf("popped front value = %d\n",myQueue.dequeue());
    myQueue.show2();
	return 0;
}

/*

https://www.youtube.com/watch?v=EFO7bbFcOMw&list=PLdo5W4Nhv31bbKJzrsKfMpo_grxuLl8LU&index=46
4.6 Implement Queue Using Stack | Data Structures

https://www.geeksforgeeks.org/queue-using-stacks/

enqueue = O(1)
dequeue = O(n)
this approach makes dequeue operation costly
*/