#include <iostream>
#include <vector>
#include <math.h> // for floor function
using std::vector;
using std::cout;
using std::endl;
void print(vector<int> &arr);
int getParentIndex(int i);
int getLeftChildIndex(int i);
int getRightChildIndex(int i);


void actualHeapify(vector<int> &arr, int parentIdx){
    printf("curr ele = %d\n",arr[parentIdx]);
    int largest = parentIdx;
    int leftChildIdx = getLeftChildIndex(parentIdx);
    int rightChildIdx = getRightChildIndex(parentIdx);
    if(leftChildIdx < arr.size() && arr[leftChildIdx] > arr[largest]){
        largest = leftChildIdx;
    }
    if(rightChildIdx < arr.size() && arr[rightChildIdx] > arr[largest]){
        largest = rightChildIdx;
    }
    if(largest != parentIdx){
        std::swap(arr[largest],arr[parentIdx]);
        cout << "after swap: ";
        print(arr);
        cout << "\n";
        actualHeapify(arr,largest);
    }
}

// TC: O(n)
void heapify(vector<int> &arr){
    for(int i=arr.size()-1; i>=0; i--){
        actualHeapify(arr,i);
        print(arr);
    }
}

int main(){
    // initial array
    // vector<int> arr {10,20,15,12,40,25,18}; // arr.size() = 7
    vector<int> arr {10,20,15,30,40}; // arr.size() = 5

    heapify(arr);
    
    cout << "heapified: ";
    print(arr);
    return 0;
}
/*
https://www.youtube.com/watch?v=HqPJF2L5h9U&t=2261s
*/


void print(vector<int> &arr){
    for(auto &val : arr)
        cout << val << " ";
    cout << endl;
}

int getParentIndex(int i){
    return floor((i-1)/2);
    // note that c++ automatically convert decimal into its floor value. So, actually you don't need to do floor((i-1)/2), but in this case I just explicitly declare the floor function so that you know the real formula using floor function.
}

int getLeftChildIndex(int i){
    return 2*i+1;
}

int getRightChildIndex(int i){
    return 2*i+2;
}
