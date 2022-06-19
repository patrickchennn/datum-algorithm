#include <bits/stdc++.h>
using std::cout;
using std::endl;
using std::vector;
using std::cin;

class Stack{
private: // attributes
    int top;
    int MAX;
    int *arr = new int[MAX] {};
public: // methods/functions

    // constructor
    Stack(int size){
        top = -1;
        MAX = size;
    }
    // prototype methods
    void show();
    bool push(int x);
    void pop();
    int peek();
    bool isEmpty();
};

int main(){
    Stack myStack = Stack(5);
    myStack.push(1);
    myStack.push(2);
    myStack.show();

    myStack.pop();
    myStack.show();

    myStack.push(123);
    myStack.show();


    // cout << std::boolalpha << myStack.isEmpty() << '\n';

	return 0;
}

int Stack::peek(){
    return arr[top];
}

void Stack::pop(){
    if(top == -1){
        cout << "Stack Underflow";
        return;
    }
    printf("%d popped out from stack\n",arr[top]);
    arr[top--] = 0;
}

bool Stack::isEmpty(){
    return (top == -1) ? true : false;
}

bool Stack::push(int inputData){
    if(top >= (MAX-1)){
        cout << "Stack Overflow";
        return false;
    }
    arr[++top] = inputData;
    cout << inputData << " pushed into stack\n";
    return true;
}

void Stack::show(){
    cout << "myStack: [ ";
    for(int i=0; i<MAX; i++){
        printf("%d ",arr[i]);
    }
    cout << ']';
    cout << endl;
}

/*
https://www.tutorialspoint.com/data_structures_algorithms/stack_algorithm.htm
https://www.geeksforgeeks.org/stack-data-structure-introduction-program/
*/