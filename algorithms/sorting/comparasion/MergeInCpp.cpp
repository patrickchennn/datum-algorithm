#include <bits/stdc++.h>
using namespace std;

void printArr(vector<int> &arr);
void printArrNoNewline(vector<int> &arr);

void merge(vector<int> &arr,vector<int> &left,vector<int> &right){
    int i=0,j=0,k=0;

    int m = left.size();
    int n = right.size();

    while(i < n && j < m){
        if(left[i] <= right[j]){
            arr[k++] = left[i++];
        }else
            arr[k++] = right[j++];
    }

    while(i < m){
        arr[k++] = left[i++];
    }

    while(j < n){
        arr[k++] = right[j++];
    }
    cout << "result ";
    printArr(arr);
    cout << "done" << "\n\n";
}

void mergeSort(vector<int> &arr){
    int arrLen = arr.size();
    int mid = arrLen/2;

    // basecase
    if(arrLen == 1)
        return;
    
    vector<int> left(mid);
    vector<int> right(arrLen-mid);
    
    for(int i=0; i<mid; i++)
        left[i] = arr[i];
    
    for(int i=mid; i<arrLen; i++)
        right[i-mid] = arr[i];

    cout << "\t--divide-- this array --> ";
    printArr(arr);

    cout << "left=";
    printArrNoNewline(left);

    cout << " right=";
    printArrNoNewline(right);

    cout << "\n\t--done divide--";
    cout << "\n\n";

    mergeSort(left);
    mergeSort(right);


    cout << "conquer and combine for " << endl;
    printArrNoNewline(left);
    cout << "  ";
    printArrNoNewline(right);
    cout << endl;

    merge(arr,left,right);
}

int main(){
    vector<vector<int>> test_case = {
        // {38,27,43,3,9,82,10},
        {9,3,7,5,6,4,8,2}
    };

    for(vector<int> &each_case : test_case){
        mergeSort(each_case);
        printArr(each_case);

    }
	return 0;
}

/*
https://www.youtube.com/watch?v=bOk35XmHPKs&t=222s
Merge Sort Algorithm in Java - Full Tutorial with Source

*/

void printArr(vector<int> &arr){
    cout << "[ ";
    for(auto &num : arr)
        cout << num << " ";
    cout << "]";
    cout << endl;
}

void printArrNoNewline(vector<int> &arr){
    cout << "[ ";
    for(auto &num : arr)
        cout << num << " ";
    cout << "]";
}