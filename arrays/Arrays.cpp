#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,val,pos;
    cin >> n >> val >> pos;

    vector<int> arr(n);

    for(int i=0; i<n; i++)
        cin >> arr[i];

    if(pos <= n && pos >= 0){
        arr.resize(n+1);
        for(int i=n; i>pos; i--){
            arr[i] = arr[i-1];
        }
        arr[pos] = val;
        for(auto &x : arr)
            cout << x << " ";
    }else
        cout << "Invalid Position" << endl;
    
    return 0;
}

/*
Input:
5 100 2
10 20 30 40 50

Output:
10 20 100 30 40 50

Input:
5 100 -1
10 20 30 40 50

Output:
5 100 10
10 20 30 40 50

Constraints:
0 <= pos <= n

https://www.log2base2.com/data-structures/array/insert-element-particular-index-array.html
https://www.youtube.com/watch?v=KELqVT7hjeE&list=PLhb7SOmGNUc5AZurO-im4t_RDr-ymjz0d&index=2
Insert an element at a particular index in an array
*/