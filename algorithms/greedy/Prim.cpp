#include <iostream>
#include <vector>
#include <climits>
using std::cout;
using std::endl;

#define INF 9999999
void printGraph(std::vector<std::vector<int>> graph);

void printMST(std::vector<int> parent, std::vector<std::vector<int>> &graph,int V)
{
    cout<<"Edge \tWeight\n";
    for (int i = 1; i < V; i++)
        cout<<parent[i]<<" - "<<i<<" \t"<<graph[i][parent[i]]<<" \n";
}

/*
A utility function to find the vertex with minimum weight value, from the set of vertices not yet visited
*/
int minweight(std::vector<int> weight,std::vector<bool> visitedVertex,int V){
    // Initialize min value
    int min = INT_MAX, min_index;
 
    for (int v = 0; v < V; v++)
        if (visitedVertex[v] == false && weight[v] < min){
            min = weight[v];
            min_index = v;
        }
 
    return min_index;
}

// Function to construct and print MST for
// a graph represented using adjacency
// matrix representation
void prim2(std::vector<std::vector<int>> &graph)
{
    /* suppose
    INT_MAX = ∞, u = source, v = destination
    */

    // before step 1 we need all of these
    int V = graph.size();
    // Array to store constructed MST
    std::vector<int> parent(V);
     
    // weight values used to pick bunch of weight value
    std::vector<int> weight(V,INT_MAX);
     
    // To represent set of vertices included in MST
    std::vector<bool> visitedVertex(V,false);
 
    /*
    Always include first 1st vertex in MST. Make weight 0 so that this vertex is picked as first vertex.
    */
    weight[0] = 0;
    parent[0] = -1; // First node is always the root of MST
 
    // The MST will have V vertices and |E| = |V|-1. So we'll loop untill |V|-1, where V is the number of vertices
    for (int count = 0; count < V - 1; count++){
        // step 1 find the minumum weight edges of current node
        int u = minweight(weight, visitedVertex,V);
 
        // true means current vertex has been visited and it
        visitedVertex[u] = true;
 
 
        // Update weight value and parent index of the adjacent vertices of the picked vertex. Consider only those vertices which are not yet visited
        for (int v = 0; v < V; v++)
            /* 3 constraints for step 3
            1.edge is present from u to v
            2.visitedVertex[v] == false only if vertices there is vertex such that has not visited
            3.edge weight is smaller than current edge weight
            */
            if (
                graph[u][v] != 0 && 
                visitedVertex[v] == false && 
                graph[u][v] < weight[v]
            ){
                parent[v] = u; // updating parent
                weight[v] = graph[u][v];
            }
    }
 
    // print the constructed MST
    printMST(parent, graph, V);
}
 

void prim1(std::vector<std::vector<int>> &graph){
    int V = graph.size();

    std::vector<bool> visitedVertex(V,false);
    visitedVertex[0] = true;

    int row,col;
    // stop at |V|-1. ie spanning tree has |V|-1 edges
    for(int count=0; count<V-1; count++){
        int myMax = INF;
        col = row = 0;

        /*
        For every vertex in the set S, find the all adjacent vertices, calculate the distance from the vertex selected at step 1. If the vertex is already in the set S, discard it otherwise choose another vertex nearest to selected vertex  at step 1
        */
        for(int i=0; i<V; i++){
            for(int j=0; j<V; j++){
                if(visitedVertex[j]==false && graph[i][j]){
                    if(graph[i][j] < myMax){
                        myMax = graph[i][j];
                        col = i;
                        row = j;
                    }
                }
            }
        }
        printf("%d--%d: %d\n",col,row,graph[col][row]);
        visitedVertex[row] = true;
    }
}

int main(){
    // suppose 0 is a null value
    // V = 5
    // picture: undirected-weighted.png
    std::vector<std::vector<int>> graph = 
    { // adjaceny matrix
        {0,3,0,0,2},
        {3,0,9,10,5},
        {0,9,0,15,0},
        {0,10,15,0,6},
        {2,5,0,6,0}
    };

    // printGraph(graph);
    // prim1(graph);
    // prim2(graph);

    // picture: graph4.png
    std::vector<std::vector<int>> graph2 =
    {
        {0,4,6,0,0,0},
        {4,0,6,3,4,0},
        {6,6,0,1,0,0},
        {0,3,1,0,2,3},
        {0,4,0,2,0,7},
        {0,0,0,3,7,0}
    };
    // prim1(graph2);
    prim2(graph2);
    return 0;
}

/*
requirement:
1.we need to keep track of weight values assigned to each node. use array(int)
2.we need to know what all vertices are included. use array(bool)
3.we need to remember the edges of mst to print it finally. use array(int)

the length of array 1,2, and 3 are the number of vertices |V|

https://www.youtube.com/watch?v=QyJ8gOss-Y8&list=PLeIMaH7i8JDiRA4fK9QmjvDSZKBJDyxpc&index=16
Prim's Algorithm for Minimum Spanning Tree | Graph Theory #13


https://www.youtube.com/watch?v=ZtZaR7EcI5Y&list=PLdo5W4Nhv31bbKJzrsKfMpo_grxuLl8LU&index=84
6.5 Prim's Algorithm for Minimum Spanning Tree | Data structures

https://www.youtube.com/watch?v=xthRL0lcx2w&t=93s
video explanation for graph4

https://www.tutorialspoint.com/data_structures_algorithms/prims_spanning_tree_algorithm.htm
https://www.programiz.com/dsa/spanning-tree-and-minimum-spanning-tree
https://www.geeksforgeeks.org/prims-minimum-spanning-tree-mst-greedy-algo-5/
*/

void printGraph(std::vector<std::vector<int>> graph){
    int vertices = graph.size();
    for (int row=0; row<vertices; row++){
        cout << row << " : ";
        for (int col=0; col<vertices; col++){
            cout << graph[row][col] << " ";
        }
        cout << "\n";
    }
}