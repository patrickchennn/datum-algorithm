#include <bits/stdc++.h>
using std::cout;
using std::endl;
using std::vector;
using std::cin;
void printArray(vector<int>& arr)
{
    for (int i = 0; i < arr.size(); i++)
        cout << arr[i] << " ";
    cout << "\n";
}

void countSort(vector<int> &arr,int n){
    // this max min things will helps us to determine the possible len of count array
    int max = *max_element(arr.begin(), arr.end());
    int min = *min_element(arr.begin(), arr.end());
    int range = max - min;

    // count occurences of each value in arr
    vector<int> count(range+1),sortedArray(n);
    // T(n) = n
    for(int i=0; i<n; i++)
        (count[arr[i]])++;
    puts("count how many each value emerged in our array:");
    printArray(count);

    /* 
    why we do this?
    we do this because we want to update index of "count arr", so that it will contains the actual position of sorted array, and how?

    we will use this input to show how to update count arr
    6
    1 0 3 1 3 1

    we need:
    1.keep the value of idx 0 as our staring value --> count[0] = 1
    2.start from idx 1

    get the sum of index 0..n-1 and 1..n values
    interval: [0,n) [1,n]
    count[0]+count[1]=x --> x=1+3 --> x=4
    x+count[2]=x1 --> 4+0=x1 --> x1=4
    x1+count[3]=x2 --> 4+2=x1 --> x2=6
    so on, and so forth ...
    */
    for(int i=1; i<=range; i++) // T(r) = r
        count[i] += count[i-1];

    puts("the actual position: ");
    printArray(count);

    for(int i=n-1; i >= 0; i--){ // T(n) = n
        int sortedIndex = (count[arr[i]]) --;
        sortedArray[sortedIndex] = arr[i];
    }
    printArray(sortedArray);

    for(int i=0; i<n; i++) // T(n) = n
        arr[i] = sortedArray[i];

    // T = O(3n+k) <=> O(n+k)
    // S = O(3n+k) <=> O(n+k)
}

int main(){
    // int n;
    // cin >> n;
    // vector<int> arr(n);
    // for(int i=0; i<n; i++) cin >> arr[i];
    // cout << endl;
    
    vector<int> arr{2, 1, 1, 0, 2 ,5,4 ,0 ,2 ,8 ,7 ,7 ,9, 2,0,1,9};
    int n = arr.size();

    /* 
    there is a constrains for countSort(), and that is 0 <= arr[i] <= r, where r is the len of count array
    */
    countSort(arr,n);
    cout << "sorted array: ";
    printArray(arr);
	return 0;
}

/*
6
1 0 3 1 3 1

17
2 1 1 0 2 5 4 0 2 8 7 7 9 2 0 1 9

https://www.youtube.com/watch?v=OKd534EWcdk
Learn Counting Sort Algorithm in LESS THAN 6 MINUTES!

https://socs.binus.ac.id/2019/12/27/counting-sort/ 

https://www.youtube.com/watch?v=pEJiGC-ObQE (best introduction)
https://www.geeksforgeeks.org/counting-sort/#:~:text=Counting%20sort%20is%20a%20sorting,object%20in%20the%20output%20sequence.
*/
