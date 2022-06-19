#include <bits/stdc++.h>
using std::cout;
using std::endl;
using std::vector;
using std::cin;
using std::string;

void revString(string &s){
    string ans="";
    std::stack<char> stack;
    for(int i=0; i<s.length(); i++){
        stack.push(s[i]);
    }
    for(int i=0; i<s.length(); i++){
        ans += stack.top();
        stack.pop();
    }

    cout << ans << endl;
}

int main(){
    string myStr = "hello";

    revString(myStr);
	return 0;
}

/*
https://www.youtube.com/watch?v=hNP72JdOIgY&list=PL2_aWCzGMAwI3W_JlcBbtYTwiQSsOTa6P&index=17
*/
