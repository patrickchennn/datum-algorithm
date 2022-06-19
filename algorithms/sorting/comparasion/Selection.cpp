#include <bits/stdc++.h>
using namespace std;

void printArrStatic(int arr[],int n);
void mySwap(int *a,int *b);

void x(int arr[],int n){
    for(int i=0; i<n-1; i++){
        for(int j=i+1; j<n; j++){
            printf("(%d,%d) ",i,j);
        }
        puts("");
    }
}

void selectionSort(int arr[],int n){
    int minIdx;
    for(int i=0; i<n-1; i++){
        minIdx = i;

        // this second loop helps to determine the min value from unsorted array
        for(int j=i+1; j<n; j++){
            // find min value index in the unsorted array
            if(arr[j]<arr[minIdx]){
                minIdx = j;
            }
        }

        printf("minIdx[%d] i[%d] --> ",minIdx,i);
        printf("swap(%d,%d) ",arr[minIdx],arr[i]);
        mySwap(&arr[minIdx],&arr[i]);
        printArrStatic(arr,n);
        cout << endl;
    }
}

int main(){
    int n; cin >> n;
    int arr[n];
    for(int i=0; i<n; i++) cin >> arr[i];

    selectionSort(arr,n);
    cout << "\n\n";
    printArrStatic(arr,n);
    x(arr,n);
}

/*
5
64 25 12 22 11

5
11 24 55 99 10

https://binus.ac.id/bandung/2019/12/algoritma-selection-sort-di-python/
https://www.geeksforgeeks.org/selection-sort/
https://www.youtube.com/watch?v=GUDLRan2DWM&list=PL2_aWCzGMAwKedT2KfDMB9YA5DgASZb3U&index=2
https://stackoverflow.com/questions/53138907/how-to-reverse-selectionsort-to-display-in-descending-order

Logic: Array is considered into two parts unsorted and sorted (initially whole array is unsorted)

selection 1.select the lowest/min element in the remaining array

swapping 2.bring it to the starting position

counter shift 3.change the counter for unsorted array by one
*/

void printArrStatic(int arr[],int n){
	for(int i=0; i<n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

void mySwap(int *a,int *b){
    int tmp = *a;
    *a = *b;
    *b = tmp;
}