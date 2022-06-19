#include <bits/stdc++.h>
using namespace std;

void printStack(stack<int> stack){
    cout << "[ ";
    while(!(stack.empty())){
        cout << stack.top() << " ";
        stack.pop();
    }
    cout << ']' << endl;
}

int main(){
    stack<int> stack1,stack2;
    stack1.push(1);
    stack1.push(2);
    stack1.push(3);
    cout << "[ TOP " << "BOTTOM ]" << endl;
    printStack(stack1);

    
    while(!(stack1.empty())){
        stack2.push(stack1.top());
        stack1.pop();
    }
    // printStack(stack1);
    printStack(stack2);
	return 0;
}

/*
reverse a stack using 2 stack principle
*/
