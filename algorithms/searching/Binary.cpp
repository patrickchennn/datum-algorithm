#include <bits/stdc++.h>
using namespace std;

int iterativeWay(int arr[],int left,int right,int target){
    int comp=1;
    while(left <= right){
        int mid = left + (right-left)/2; 
        printf("Comparasion %d\n",comp);
        printf("middle_index = %d + (%d-%d)/2 --> %d\n",
            left,right,left,mid);

        // return when value is equal
        if(arr[mid] == target){
            printf("%d == %d\n",arr[mid],target);
            return mid;
        }

        // ignore left if TRUE that target >
        if(arr[mid] < target){
            left = mid + 1;
            printf("left = %d\n",left);
            printf("%d < %d\n",arr[mid],target);
        }
        // ignore right if TRUE that target <
        if(arr[mid] > target){
            right = mid - 1;
            printf("right = %d\n",right);
            printf("%d > %d\n",arr[mid],target);
        }
        ++comp;
        cout << endl;
    }
    return -1;
}

int recursiveWay(int arr[],int left,int right,int target){
    if(left <= right){
        int mid = left + (right-left)/2;
        if(arr[mid]==target) return mid;
        if(arr[mid]<target)
            return recursiveWay(arr,mid+1,right,target);

        // if arr[mid] > target <=> target < arr[mid]
        return recursiveWay(arr,left,mid-1,target);
    }
    return -1;
}

int main(){
    int n,target;
    cin >> n >> target;
    // vector<int> arr(n);
    int arr[n];
    for(int i=0; i<n; i++){
        cin >> arr[i];
        cout << i << "  ";
    }
    cout << endl << endl;

    // int res = recursiveWay(arr,0,n-1,t);
    int res = iterativeWay(arr,0,n-1,target);
    if(res==-1)
        puts("Element is not presented in array");
    else
        printf("Element is at index %d\n",res);
    return 0;
}

/*
10 31
10 14 19 26 27 31 33 35 42 44


g++ Binary.cpp -o Binary

https://www.khanacademy.org/computing/computer-science/algorithms/binary-search/a/binary-search
https://www.geeksforgeeks.org/binary-search/
https://www.tutorialspoint.com/data_structures_algorithms/binary_search_algorithm.htm
https://www.geeksforgeeks.org/complexity-analysis-of-binary-search/
*/