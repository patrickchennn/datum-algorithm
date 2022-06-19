#include <bits/stdc++.h>
using namespace std;

void arrSearch(vector<int> arr,int n,int key){
    bool flag;
    int index;
    for(int i=0; i<n; i++){
        if(arr[i]==key){
            flag=true;
            index=i;
            break;
        }
    }
    if(flag==true)
        cout << "Value found at idx " << index << endl;
    else
        cout << "Value Not Found" << endl;
}

void deleteArr(vector<int> arr,int n,int val){
    int index;
    for(int i=0; i<n; i++){
        if(arr[i] == val){
            index = i;
            break;
        }
    }
    // arr.erase(arr.begin()+index);
    // cout << "index " << index << endl;
    for(int i=index; i<n-1; i++)
        arr[i] = arr[i+1];
    
    arr.erase(arr.end()-1);
    for(int x : arr) cout << x << " ";
}

int main(){
    int n,val;
    cin >> n >> val;
    vector<int> arr(n);
    for(int i=0; i<n; i++) cin >> arr[i];

    // deleteArr(arr,n,val);
    arrSearch(arr,n,val);
    // bool test = true;
    // cout << test << endl;
    return 0;
}
/*
5 78
1 20 5 78 30


5 30
10 30 5 100 4

5 500
10 30 5 100 4
https://www.log2base2.com/data-structures/array/searching-an-element-in-an-array.html
https://www.log2base2.com/data-structures/array/remove-a-specific-element-from-array.htmlhttps://www.youtube.com/watch?v=KELqVT7hjeE&list=PLhb7SOmGNUc5AZurO-im4t_RDr-ymjz0d&index=2
*/



