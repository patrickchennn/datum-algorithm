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

void insertMaxHeapify(vector<int> &binHeap,int currItemIdx){
    int parentIdx = getParentIndex(currItemIdx);

    if(parentIdx >= 0){
        if(binHeap[currItemIdx] > binHeap[parentIdx]){
            std::swap(binHeap[currItemIdx], binHeap[parentIdx]);
            insertMaxHeapify(binHeap,parentIdx);
        }
    }
}

void insert(vector<int> &binHeap,int newItem){
    binHeap.push_back(newItem);
    // length of the list - 1 because in CS we count from zero :)
    insertMaxHeapify(binHeap,binHeap.size()-1);
}


// rectify the heap so that it satisfy the definition of the heap binary tree.
void deleteMaxHeapify(vector<int> &binHeap,int heapSize,int parentIdx){
    // to trace who has the largest element is it the left or the right one?
    // set the largest to the parent because if the condition does not happen, then the largest element is held by their parent(root)
    int largest = parentIdx;
    int leftChildIdx = getLeftChildIndex(parentIdx);
    int rightChildIdx = getRightChildIndex(parentIdx);

    if(leftChildIdx < heapSize && binHeap[leftChildIdx] > binHeap[largest]){
        largest = leftChildIdx;
    }
    if(rightChildIdx < heapSize && binHeap[rightChildIdx] > binHeap[largest]){
        largest = rightChildIdx;
    }
    // swap the left and right child IF one of them greater than its parent(root)
    if(largest != parentIdx){
        std::swap(binHeap[largest],binHeap[parentIdx]);
        deleteMaxHeapify(binHeap,heapSize,largest);
    }
}

/*
This function basically delete all the elements of the heap.
*/
void sortTheHeap(vector<int> &binHeap){
    int i=binHeap.size();
    while(--i){
        printf("i=%d\n",i);

        // replace the root with the last element
        std::swap(binHeap[0],binHeap[i]);
        print(binHeap);
        // binHeap[0] = binHeap[i];

        // delete the last element
        // binHeap.pop_back();

        // rectify the heap so that it satisfy the definition of the heap binary tree.
        deleteMaxHeapify(binHeap,i,0);
        print(binHeap);
        cout << "\n";
    }
    cout << "Sorted Tree: ";
    print(binHeap);
}

int main(){
    vector<int> binHeap;
    insert(binHeap,10);
    insert(binHeap,20);
    // print(binHeap);
    insert(binHeap,15);
    // print(binHeap);

    insert(binHeap,30);
    insert(binHeap,40);
    cout << "ori: ";
    print(binHeap);

    sortTheHeap(binHeap);

    // vector<int> binHeap2 {10,20,15,30,40};
    return 0;
}

/*
https://www.youtube.com/watch?v=HqPJF2L5h9U&list=PLDN4rrl48XKpZkf03iYFl-O29szjTrs_O&index=32
30:12

https://www.geeksforgeeks.org/heap-sort/?ref=lbp
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