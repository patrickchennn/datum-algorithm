#include <bits/stdc++.h>
using namespace std;
void printVector1d(std::vector<int> &arr);

void partition(vector<int> &arr,int start,int end){
    int pivot = arr[end];
    int partitionIndex = start;


    
    return;
}

int main(){
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i=0; i<n; i++)
        cin >> arr[i];

    partition(arr,0,n-1);
    printVector1d(arr);

	return 0;
}

/*
5
4 5 3 7 2

8
7 2 1 6 8 5 3 4

https://codereview.stackexchange.com/questions/77782/quick-sort-implementation
https://www.hackerrank.com/challenges/quicksort1/problem?h_r=next-challenge&h_v=zen
*/

void printVector1d(std::vector<int> &arr){
	for(auto &x : arr)
		cout << x << " ";
	cout << endl;
}