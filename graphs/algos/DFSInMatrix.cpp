#include <iostream>
#include <stack>
#include <string>
#include <vector>
#include <utility> // for pair<>

using std::cout;
using std::string;
using std::endl;
using std::pair;
void print2dVector(std::vector<std::vector<int>> &arr){
    for(auto &row : arr){
        for(auto &item : row){
            cout << item << " ";
        }
        cout << '\n';
    }
}
void print2dVector(std::vector<std::vector<bool>> &arr){
    for(auto row : arr){
        for(auto item : row){
            cout << item << " ";
        }
        cout << '\n';
    }
}

/* - Iteratively dfs & complexity
description:
m=total row
n=total column

TC: O(n*m)
SC: O(n*m)
*/
void dfs1(std::vector<std::vector<int>> &arr){
    int h = arr.size();
    int l = arr[0].size();
    std::stack<pair<int,int>> S;

    std::vector<std::vector<bool>> visited(h,std::vector<bool> (l,0));

    print2dVector(visited);
    S.push({0,0});

    while(!S.empty()){
        pair<int,int> curr = S.top();
        S.pop();
        int row = curr.first;
        int col = curr.second;
        printf("row=%d - col=%d\n",row,col);
        if(row<0 || col<0 || row>=h || col>=l || visited[row][col]){
            printf("if: col=%d row=%d\n",col,row);
            continue;
        }

        visited[row][col] = true;

        // cout << arr[row][col] << " ";
        cout << arr[row][col] << "\n\n";


        S.push({row,(col-1)}); // left
        S.push({row,(col+1)}); // right
        S.push({(row-1),col}); // up
        S.push({(row+1),col}); // down
    }
}


/* Recursively dfs
*/
void dfs2(std::vector<std::vector<int>> &arr){
    return;
}

int main(){
    // std::vector<std::vector<int>> grid = {
    //     {-1,2,3},
    //     {0,9,8},
    //     {1,0,1}
    // };// grid[1][2] = 9;

    std::vector<std::vector<int>> grid = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12},
        {13, 14, 15, 16}
    };

	print2dVector(grid);

    dfs1(grid);
	return 0;
}

/*

*/