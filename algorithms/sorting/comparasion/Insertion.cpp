#include <bits/stdc++.h>
using namespace std;
void printArrStatic(int arr[],int n);

void insertionSort(int arr[],int n){
    puts("");
    int currentValue,shift;
    int count=0;

    // why we loop from 1? because we divide the array into 2 parts unsorted and sorted
    for(int i=1; i<n; i++){
        // selects the first unsorted element
        currentValue = arr[i];
        shift = i;
        printf("i=%d shift=%d\n",i,shift);
        while(shift>0 && arr[shift-1] > currentValue){
            // this loop shifts all the elements to right to create the position for unsorted element

            printf("arr[%d] = arr[%d] --> %d = %d\n",
            shift,shift-1,arr[shift],arr[shift-1]);

            arr[shift] = arr[shift-1];
            printArrStatic(arr,n);
            shift--;
            ++count; // 
        }
        arr[shift] = currentValue; // this inserts the unsorted element to its correct position
        printArrStatic(arr,n);
    }
    cout << count << endl;
}

int main(){
    int n; cin >> n;
    int arr[n];
    for(int i=0; i<n; i++) cin >> arr[i];
    insertionSort(arr,n);
    printArrStatic(arr,n);
    return 0;
}

/*
4
4 2 3 1

1 2 3 4

https://www.geeksforgeeks.org/insertion-sort/
https://www.hackerrank.com/challenges/tutorial-intro/problem
https://www.youtube.com/watch?v=ep8uG1IBApQ
Insertion Sort | Logical Programming in C | by Mr.Srinivas

https://www.youtube.com/watch?v=i-SKeOcBwko&list=PL2_aWCzGMAwKedT2KfDMB9YA5DgASZb3U&index=4
Insertion sort algorithm

https://upload.wikimedia.org/wikipedia/commons/0/0f/Insertion-sort-example-300px.gif
an animation how does insertion works
*/

void printArrStatic(int arr[],int n){
	for(int i=0; i<n; i++)
        cout << arr[i] << " ";
    cout << endl;
}