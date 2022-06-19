#include <iostream>
#include <queue>
#include <vector>
#include <utility> // for pair
using std::vector;
using std::cout;
using std::endl;
using std::pair;


void bfs(vector<vector<int>> &grid){
// row = m = 4
// col = n = 4
    int m = grid.size();
    int n = grid[0].size();
    int row,col;
    vector<vector<bool>> visited(m, vector<bool> (n,0));
    std::queue<pair<int,int>> Q;
    Q.push({0,0});
    int i=0;
    while(!Q.empty()){
        // coor = "coordinate" like (x,y) in diagram cartesius
        pair<int,int> coor = Q.front();
        row = coor.first;
        col = coor.second;
        Q.pop();
        printf("i=%d --> (%d,%d)\n",i,row,col);
        
        if(row==-1 || row==m || col==-1 || col==n || visited[row][col]){
            continue;
        }
        
        // cout << grid[row][col] << " ";
        cout << grid[row][col] << "\n\n";
        visited[row][col] = 1;

        Q.push({row,col-1}); // left
        Q.push({row,col+1}); // right
        Q.push({row-1,col}); // up
        Q.push({row+1,col}); // down
    }
}

int main(){
    vector<vector<int>> grid = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12},
        {13, 14, 15, 16}
    };
    bfs(grid);
	
	return 0;
}
/*
  0 1 2 3
0
1
2
3

*/

/*
https://algorithms.tutorialhorizon.com/breadth-first-search-bfs-in-2d-matrix-2d-array/
https://www.geeksforgeeks.org/breadth-first-traversal-bfs-on-a-2d-array/
*/