#include <bits/stdc++.h>
using namespace std;

void printVector(std::vector<int> arr){
    for(auto x:arr)
        cout << x <<" ";
    cout << endl;
}

void printVector(std::vector<long int> arr){
    for(auto x:arr)
        cout << x <<" ";
    cout << endl;
}

#define NIL 0
#define MAX 10

vector<long int> memo(MAX);

// int fib_hash(int n){
//     map<int,int> memo;

// // base case or it's a definition of fib
//     memo.insert({0,0});
//     memo.insert({1,1});
//     if(n<=1) return n;


//     if(memo.count(n)) return memo.find(memo.ben);

//     int nThValue = fib_hash(n-1) + fib_hash(n-2);
//     memo.insert({n,nThValue});
//     return nThValue;
// }

long int fib(int n){
    if(n <= 1)
        return n;
    return fib(n-1) + fib(n-2);
}

int fib_iterative_tabu(int n){
    // base case
    if(n<=1)return n;
    
    int fn,f0=0,f1=1;
    // while(n-- >= 2){
    for(int i=2; i<=n; i++){
        fn=f1+f0;
        f0=f1;
        f1=fn;
        printf("f-%d = %d\n",i,fn);
    }
    return fn;
}

void fib_iterative_memo(int n){
    if(n<=1) cout << n << endl;
    vector<long int> memo(n+1);
    memo[0] = 0;
    /*
    actually we don't need to store memo[0] = 0
    because when declaring vector with defined size.
    vector by it self will immediately
    sets all the value to 0. So, memo[1] = 1 would be enough
    */
    memo[1] = 1;
    for(int i=2; i<=n; i++){
        memo[i] = memo[i-1]+memo[i-2];
    }
    printVector(memo);
    cout << memo[n] << endl;
}

long int fib_recursive_memo(int n) {
    // vector<long int> memo(n+100);
    assert(n < MAX);
    // if(memo[n] == NIL) {
    //     if(n <= 1)
    //         return n;
    //     else
    //         memo[n] = fib_recursive_memo(n-1) + fib_recursive_memo(n-2);
    // }
    // printVector(memo);
    // return memo[n];

    //base case
    if(n<=1) return n;

    if(memo[n]!=0) return memo[n]; // method1. I prefer this one cause it's obvious, and what it means basically check if our n is in memo or not, if n is in memo then we can simply return
    // if(memo[n]) return memo[n]; // method2

    // either this
    memo[n] = fib_recursive_memo(n-1) + fib_recursive_memo(n-2);
    printVector(memo);
    puts("");
    return memo[n];

    // or this will work
    // return memo[n] = fib_recursive_memo(n-1) + fib_recursive_memo(n-2);

}

void fib_iterative_tabu2(int n){
    vector<int> fib(n+1);
    fib[1] = 1;
    for(int i=0; i<=n; i++){
        fib[i+1] += fib[i];
        fib[i+2] += fib[i];
        printf("i = %d --> ",i);
        printVector(fib);
    }
    cout << fib[n] << endl;
}

int main() {
    int n;
    long int fibonnaci;
    // memo.assign(NIL,MAX);
    cout << " n = ";
    cin >> n;
    if(n<0){
        puts("Index is a negative. No such thing as a negative index in a series.");
        std::exit(1);
    }

// naive solution t(n)=O(2^n) | s(n)=O(n)
    // cout << fib(n) << endl;

// memoized solution(Top Down Approach) t(n)=O(n) | s(n)=O(n)
    // cout << fib_recursive_memo(n) << endl;

// memoized iterative
    // fib_iterative_memo(n);

// iterative tabulation TC: O(n). SC: O(1)
    // cout << fib_iterative_tabu(n) << endl;

// iterative tabulation with auxillary space
// TC: O(n) SC: O(n)
    fib_iterative_tabu2(n);

// fib hash
    // cout << fib_hash(n) << endl;
    return 0;
}

/*
fib(n) 0 1 1 2 3 5 8 13
n      0 1 2 3 4 5 6 7


https://poanchen.github.io/blog/2018/02/09/Solving-the-Fibonacci-problem-using-Dynamic-Programming-in-Java
https://leetcode.com/problems/fibonacci-number/
https://leetcode.com/problems/fibonacci-number/discuss/1159784/Easy-Solution-w-Multiple-Approaches-Explained-!
https://www.geeksforgeeks.org/overlapping-subproblems-property-in-dynamic-programming-dp-1/

https://stackoverflow.com/questions/6184869/what-is-the-difference-between-memoization-and-dynamic-programming

https://programming.guide/dynamic-programming-vs-memoization-vs-tabulation.html

http://www.maths.surrey.ac.uk/hosted-sites/R.Knott/Fibonacci/fibFormula.html
*/