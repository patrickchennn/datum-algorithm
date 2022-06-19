#include <iostream>
#include <vector>
using namespace std;

int fibMemoRecursive(int n){
    std::vector<int> memo(n+1);

    // base case
    if(n<=1) return n;

    memo[0] = 0; // f0 = 0
    memo[1] = 1; // f1 = 1

    if(memo[n] != 0) return memo[n];
    memo[n] = fibMemoRecursive(n-1) + fibMemoRecursive(n-2);
    return memo[n];
}

int main(){
    int n;
    cin >> n;
    if(n < 0){
        cout << "n can't be negative!";
        exit(1);
    }

    cout << fibMemoRecursive(n) << endl;
    return 0;
}

/*

*/