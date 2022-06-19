#include <iostream>
#include <unordered_set>
#include <queue> // for BFS
#include <vector>
using std::cout;
using std::endl;

class Graph{
private:
    std::vector<bool> visitedVertex;
    std::vector<std::vector<int>> graph;
    int vertices;
    bool isCylicUtil(int,int);

public:
    Graph(int);
    void addEdgeU(int,int);
    void addEdge(int,int);
    void printGraph();
    bool isCylic();
    bool isCylic2();
};

// like dfs
bool Graph::isCylicUtil(int currVertex,int parent){
    // mark visited node as true
    visitedVertex[currVertex] = true;

    // for each node find its adjacent node
    for(auto &adj : graph[currVertex]){
        // if adjacent node has not been visited
        if(!visitedVertex[adj]){
            if(isCylicUtil(adj,currVertex))
                return true;
        }
        /*
        If an adjacent vertex is visited and not the parent of current vertex, then there exists a cycle in the graph.
        */

       // any node other than previous node(parent node) if visited means it graph contains a cycle
        else if(adj != parent){
            printf("adj=%d parent=%d\n",adj,parent);
            return true;
        }
    }
    return false;
}

// DFS method
bool Graph::isCylic(){
    for(int v=0; v<this->vertices; v++){
        if(!visitedVertex[v])
            if(isCylicUtil(v,-1))
                return true; // return true if graph contains a cycle
    }
    return false; // else return false
}

// coloring method
// bool Graph::isCylic2(){
    
// }

int main(){
    // graph 1 (true)
    // Graph g(5);
    // g.addEdgeU(1,0);
    // g.addEdgeU(0,2);
    // g.addEdgeU(0,3);
    // g.addEdgeU(3,4);
    // g.addEdgeU(2,1);

    // g.printGraph();

    // // graph 2 (false)
    // Graph g2(5);
    // g2.addEdgeU(1,3);
    // g2.addEdgeU(3,4);
    // g2.printGraph();
    // bool ans2 = g2.isCylic();
    // cout << std::boolalpha << ans2 << endl;

    // // picture: https://www.youtube.com/watch?v=Y9NFqI6Pzd4
    // // graph 3 (true)
    // Graph g3(9);
    // g3.addEdgeU(2,5);
    // g3.addEdgeU(5,6);
    // g3.addEdgeU(6,7);
    // g3.addEdgeU(7,8);
    // g3.addEdgeU(5,8);
    // g3.printGraph();
    // bool ans3 = g3.isCylic();
    // cout << std::boolalpha << ans3 << endl;

    // // picture: https://www.youtube.com/watch?v=L0DcePeWHnM&list=PLEJXowNB4kPzByLnnFYNSCoqtFz0VKLk5&index=7
    Graph g4(4);
    g4.addEdgeU(0,1);
    g4.addEdgeU(0,2);
    g4.addEdgeU(0,3);
    g4.addEdgeU(2,3);
    g4.printGraph();
    // true cycle at 0--2--3
    bool ans4 = g4.isCylic();
    cout << std::boolalpha << ans4 << endl;


    return 0;
}

/*
for union find approach take a look at "disjoint-set or union-find" folder

https://www.youtube.com/watch?v=Y9NFqI6Pzd4
recommended video explanation+code implementation

https://www.youtube.com/watch?v=vXrv3kruvwE&list=PLdo5W4Nhv31bbKJzrsKfMpo_grxuLl8LU&index=88
white board explanation

https://www.geeksforgeeks.org/detect-cycle-undirected-graph/
good article

https://leetcode.com/problems/redundant-connection/
problems
*/

Graph::Graph(int vertices){
    this->vertices = vertices;
    this->graph.resize(vertices);
    this->visitedVertex.resize(vertices,false);
}

void Graph::addEdgeU(int src,int dst){
    graph[src].push_back(dst);
    graph[dst].push_back(src);
}
void Graph::addEdge(int src,int dst){
    graph[src].push_back(dst);
}

void Graph::printGraph(){
    for (int vertex = 0; vertex < this->vertices; vertex++) {
        printf("\nvertex %d",vertex);
        for(auto &adj : graph[vertex]){
            printf(" --> %d",adj);
        }
        cout << '\n';
    }
}