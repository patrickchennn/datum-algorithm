#include <iostream>
using namespace std;

// Tabulated version to find factorial x.


int main(){
    int MAXN = 5;
    int dp[MAXN];

    // base case
    dp[0] = 1;
    for (int i = 1; i<=MAXN; i++)
    {
        dp[i] = dp[i-1] * i;
    }

    for(int i=0; i<MAXN; i++){
        printf("%d ",dp[i]);
    }
    cout << endl;
    return 0;
}