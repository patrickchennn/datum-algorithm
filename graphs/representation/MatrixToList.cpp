#include <iostream>
#include <vector>
using std::cout;
using std::endl;

void printGraph(std::vector<std::vector<int>> g){
    for(int v=0; v<g.size(); v++){
        cout << "vertex " << v;
        for(auto &adj : g[v]){
            printf(" --> %d", adj);
        }
        cout << '\n';
    }
}

std::vector<std::vector<int>> toAdjList(std::vector<std::vector<int>> &matrix){
    int V = matrix.size();
    std::vector<std::vector<int>> adjList(V);
    for(int i=0; i<V; i++){
        for(int j=0; j<V; j++){
            if(matrix[i][j] > 0){
                adjList[i].push_back(j);
            }
        }
    }
    return adjList;
}

int main(){
    int V = 5;
    // picture: undirected.png
    std::vector<std::vector<int>> matrix = {
        {0,1,0,0,1},
        {1,0,1,1,1},
        {0,1,0,1,0},
        {0,1,1,0,1},
        {1,1,0,1,0}
    };

    std::vector<std::vector<int>> adjList = toAdjList(matrix);
    printGraph(adjList);
    return 0;
}

/*
https://www.geeksforgeeks.org/convert-adjacency-matrix-to-adjacency-list-representation-of-graph/
*/