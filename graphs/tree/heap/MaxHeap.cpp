#include <iostream>
#include <vector>
#include <math.h> // for floor function
using std::vector;
using std::cout;
using std::endl;

int getParentIndex(int i);
int getLeftChildIndex(int i);
int getRightChildIndex(int i);
void print(vector<int> &binHeap);
void mySwap(int &a,int &b);

// this function is helping us to rectify the tree heap so that it will satisfy the definition of heap DS.
// TC for insert element in heap DS: O(log h)
void heapifyInsertMax(vector<int> &binHeap,int currItemIdx){
    int parentIdx = getParentIndex(currItemIdx);

    // basecondition for recursive call*
    if(parentIdx >= 0){
        /*
        if current item is greater than its parent, swap them and call recursively to check untill top.
        */
        if(binHeap[currItemIdx] > binHeap[parentIdx]){
            printf("swap(%d,%d)\n",binHeap[parentIdx],binHeap[currItemIdx]);
            mySwap(binHeap[currItemIdx],binHeap[parentIdx]);

            // *
            heapifyInsertMax(binHeap,parentIdx);
        }
    }
}

void insert(vector<int> &binHeap,int newItem){
    binHeap.push_back(newItem);

    int currItemIdx = binHeap.size()-1;
    heapifyInsertMax(binHeap,currItemIdx);
}

// This function is helping us to rectify the tree heap so that it satisfies the definition of binary heap DS.
// TC for delete element in heap DS: O(logh)
void heapifyMaxDelete(vector<int> &binHeap,int parentIdx){
    int largestIdx = parentIdx;
    int leftChildIdx = getLeftChildIndex(parentIdx);
    int rightChildIdx = getRightChildIndex(parentIdx);

    // if left child value > its parent value
    if(binHeap[leftChildIdx] > binHeap[rightChildIdx]){
        // then the largestIdx value is held by left child
        largestIdx = leftChildIdx;
    }
    else{
        // right child value > its parent value
        largestIdx = rightChildIdx;
    }
    if(binHeap[largestIdx] > binHeap[parentIdx]){
        mySwap(binHeap[leftChildIdx],binHeap[rightChildIdx]);
        heapifyMaxDelete(binHeap,largestIdx);
    }

}

void deleteRoot(vector<int> &binHeap){
    binHeap[0] = binHeap[binHeap.size()-1];
    binHeap.pop_back();
    
    print(binHeap);

    heapifyMaxDelete(binHeap,0);
    cout << "Deleted: ";
    print(binHeap);
}

// TC for getting maximum element in heap DS: O(1)
int getMax(vector<int> &binHeap){
    return (binHeap.size()>0) ? binHeap[0] : -1;
}

int main(){
    vector<int> binHeap = {50,30,20,15,10,8,16};

    print(binHeap);
    printf("max=%d\n",getMax(binHeap));
    // The length of the list we substracted by 1 because in CS we count from zero. :)
    // deleteRoot(binHeap);

    // insert(binHeap,60);
    return 0;
}

void print(vector<int> &binHeap){
    for(int &num : binHeap)
        cout << num << " ";
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

void mySwap(int &a,int &b){
    int tmp = a;
    a = b;
    b = tmp;
}

/*
Preposition:
For all parent, it is obligatory that it has value > or ==(>=) than its descendant.
for every value parent, parent >= descendant

Description:
h is the height of the tree

https://www.youtube.com/watch?v=pLIajuc31qk
Heaps, heapsort, and priority queues - Inside code

https://www.youtube.com/watch?v=HqPJF2L5h9U&list=PLDN4rrl48XKpZkf03iYFl-O29szjTrs_O&index=32
2.6.3 Heap - Heap Sort - Heapify - Priority Queues

Heap max insertion (16:36)

Delete item (22:24)

https://www.geeksforgeeks.org/insertion-and-deletion-in-heaps/
*/
