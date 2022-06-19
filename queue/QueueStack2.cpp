#include <bits/stdc++.h>
using namespace std;

class Queue{
public:
    vector<int> stack1;
    vector<int> stack2;

    stack<int> s1,s2;

    void enqueue(int inputData){
        // Move all elements from s1 to s2
        if(s1.empty())
        while (!(s1.empty())){
            s2.push(s1.top());
            stack2.push_back(s1.top());
            s1.pop();
        }

        // Push item into s1
        s1.push(inputData);

        // Push everything back to s1
        while (!(s2.empty())){
            s1.push(s2.top());
            stack1.push_back(s2.top());
            s2.pop();
        }
    }

    // Dequeue an item from the queue
    int dequeue(){
        // if first stack is empty
        if (s1.empty()) {
            cout << "Q is Empty";
            exit(0);
        }

        // Return top of s1
        int x = s1.top();
        s1.pop();
        return x;
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