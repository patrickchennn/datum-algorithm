#include <bits/stdc++.h>
using namespace std;
void x(int arr[],int n){
    for(int i=0; i<n-1; i++){
        for(int j=0; j<n-i-1; j++){
            printf("(%d,%d) ",i,j);
        }
        puts("");
    }
}

void printArrStatic(int arr[],int n);
void mySwap(int *a,int *b);

void bubbleSort(int arr[],int n){
    for(int i=0; i<n-1; i++){
        for(int j=0; j<n-i-1; j++){
            if(arr[j] > arr[j+1]){
                cout << "SWAP THIS! ";
                printf("i=%d arr[%d] > arr[%d] = %d > %d\n",i,j,j+1,arr[j],arr[j+1]);
                mySwap(&arr[j], &arr[j+1]);
                printArrStatic(arr,n);
                cout << endl;
            }else{
                printf("i=%d arr[%d] !> arr[%d] = %d > %d\n",i,j,j+1,arr[j],arr[j+1]);
            }
        }
    }
}

// a little bit optimized bubble sort
void bubbleSort2(int arr[], int n){
    bool swapped;
    for(int i=0; i<n-1; i++){
        swapped=false;
        for(int j=0; j<n-1-i; j++){
            if(arr[j] > arr[j+1]){
                swapped=true;
                cout << "SWAP THIS! ";
                printf("i=%d arr[%d] > arr[%d] = %d > %d\n",i,j,j+1,arr[j],arr[j+1]);
                mySwap(&arr[j], &arr[j+1]);
                printArrStatic(arr,n);
                cout << endl;
            }else{
                printf("i=%d arr[%d] !> arr[%d] = %d > %d\n",i,j,j+1,arr[j],arr[j+1]);
            }
        }
        if(swapped==false)
            break;
    }
}

// recursive bubble sort
void bubbleSortRecursive(int arr[],int n){
    if(n==1)
}

int main(){
    int n; cin >> n;
    int arr[n];
    for(int i=0; i<n; i++)
        cin >> arr[i];

    bubbleSort2(arr,n);
    printArrStatic(arr,n);
    // x(arr,n);
    return 0;
}

/*
4
5 1 4 2

5
1 2 3 4 5
https://www.tutorialspoint.com/data_structures_algorithms/bubble_sort_program_in_c.htm
https://www.tutorialspoint.com/data_structures_algorithms/bubble_sort_algorithm.htm

https://www.geeksforgeeks.org/bubble-sort/
https://www.geeksforgeeks.org/recursive-bubble-sort/
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