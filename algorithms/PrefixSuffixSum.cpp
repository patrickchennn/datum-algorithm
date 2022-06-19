#include <iostream>
#include <vector>
using std::cout;
using std::endl;

void print(std::vector<int> &arr){
    for(int &val : arr){
        cout << val << " ";
    }
    cout << "\n";
}

void prefixSum(std::vector<int> &arr){
    int n = arr.size();
    std::vector<int> p(n);
    p[0] = arr[0];
    for(int i=1; i<n; i++){
        p[i] = p[i-1] + arr[i];
    }
    cout << "prefix sum: ";
    print(p);
}
 
void suffixSun(std::vector<int> &arr){
    int n = arr.size();
    std::vector<int> p(n);
    n-=1;// 4
    p[n] = arr[n];
    //i=3
    for(int i=n-1; i>=0; i--){
        cout << "n " << i<< "\n";
        p[i] = arr[i] + p[i+1];
    }
    cout << "suffix sum: ";
    print(p);
}

int main(){
	std::vector<int> arr {10, 20, 10, 5, 15};

    prefixSum(arr);
    print(arr);
    suffixSun(arr);
	return 0;
}

/*
https://www.youtube.com/watch?v=7pJo_rM0z_s
Prefix Sum Array Explained

https://www.geeksforgeeks.org/prefix-sum-array-implementation-applications-competitive-programming/

https://www.geeksforgeeks.org/suffix-sum-array/#:~:text=Suffix%20Sum%20is%20a%20precomputation,of%20the%20array%20is%20computed.
*/