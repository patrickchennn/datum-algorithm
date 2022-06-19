#include <bits/stdc++.h>
using namespace std;

void search(vector<int> arr,int n,int t){
    bool flag=0;
    int index;
    for(int i=0; i<n; i++){
        if(arr[i]==t){
            index = i;
            flag=1;
            break;
        }
    }
    flag ? printf("Data found at index %d\n",index) : puts("Data not found");
}

int main(){
    int n,t;
    cin >> n >> t;
    vector<int> arr(n);
    for(int i=0; i<n; i++) cin >> arr[i];

    search(arr,n,t);
    return 0;
}



/*
5 4
2 3 4 5 6

10 20
1 2 3 4 5 6 7 8 9 10

200 142
49 132 169 184 200 190 146 127 104 28 66 48 17 20 74 2 2 93 142 65 89 96 32 93 3 117 53 146 25 37 52 142 163 124 131 151 137 76 143 93 114 53 14 32 94 135 181 180 77 41 54 174 197 172 31 196 166 152 142 19 12 178 183 23 147 72 3 137 84 178 127 161 90 23 111 181 109 175 5 8 21 30 188 62 37 195 174 189 145 65 145 103 66 96 106 54 90 180 191 46
*/