#include <iostream>
using namespace std;

int gridTraveler(int m,int n){
    if(m==0 || n==0) return 0;
    if(m==1 && n==1) return 1;
    // if(m==1 || n==1) return abs(m-n);
    // if(m==1 || n==1){
    //     if(m==1 && n==1){
    //         return 1;
    //     }
    //     return abs(m-n);
    // }
    return gridTraveler(m-1,n) + gridTraveler(m,n-1);
}

int main(){
    cout << gridTraveler(1,1) << endl; // 1
    cout << gridTraveler(2,3) << endl; // 3
    cout << gridTraveler(3,2) << endl; // 3
    cout << gridTraveler(3,3) << endl; // 6
    // cout << gridTraveler(18,18) << endl;

    return 0;
}
/*
problem:
say that you are a traveler on a 2d grid. You begin in the top-left corner and your goal is to travel to the bottom-right corner. You may only move down or right.

In how many ways can you travel to the goal on a grid with dimensions m*n?

Write a function "gridTraveler(m,n)" that calculates this.
m=row
n=column
*/