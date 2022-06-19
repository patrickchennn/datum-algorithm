#include <iostream>
#include <vector>
using std::endl;
using std::cout;

class Graph{
private:
    int V;
    std::vector<bool> visitedVertex;
    std::vector<bool> currVisited;
    std::vector<std::vector<int>> graph;
    bool isCyclicUtil(int);
public:
    Graph(int);
    void addEdge(int,int);
    void printAdjList();
    bool isCyclic();
};

bool Graph::isCyclicUtil(int v){
    // then mark both as true(already visited)
    visitedVertex[v] = true;
    currVisited[v] = true;
    
    // for each node we check its adj nodes only if node available (like DFS)
    for(auto &adj : this->graph[v]){
        // if adjacent node has not been visited
        if(!visitedVertex[adj]){
            if(isCyclicUtil(adj)){
                return true;
            }
        }else if(currVisited[adj]==true){ // if true then the graph contains a cycle
            return true;
        }
    }
    // whenever you meet vertex such that they don't have any adjacent vertex OR that vertex were recently visited, mark currVisited as false and return false, because there is nothing we can do on that particular vertex.
    currVisited[v] = false;
    return false;
}

bool Graph::isCyclic(){
    for(int v=0; v<this->V; v++){
        // if vertex has not been visited
        if(!visitedVertex[v]){
            if(isCyclicUtil(v))
                return true; // graph contains a cycle
        }
    }
    return false; // graph does not contain a cycle
}

int main(){
    // // picture: https://media.geeksforgeeks.org/wp-content/cdn-uploads/20190704130006/DetectCycleInaDirectedGraph.png
    // Graph g(4);
    // g.addEdge(0,1);

    // loop: (0)-->2-->(0)
    // g.addEdge(0,2);
    // g.addEdge(1,2);
    // g.addEdge(2,0);
    // g.addEdge(2,3);
    // g.addEdge(3,3); // parallel edge
    // g.printAdjList();
    // bool ans = g.isCyclic();
    // cout << std::boolalpha << ans << endl;
    
    // // picture: https://www.youtube.com/watch?v=uzVUw90ZFIg
    // Graph g2(10);
    // g2.addEdge(1,2);
    // g2.addEdge(2,3);
    // g2.addEdge(3,4);
    // g2.addEdge(4,5);
    // g2.addEdge(3,6);
    // g2.addEdge(6,5);
    // g2.addEdge(7,2);

    // // loop: (7)-->8-->9-->(7)
    // g2.addEdge(7,8);
    // g2.addEdge(8,9);
    // g2.addEdge(9,7);

    // g2.printAdjList();

    // bool ans2 = g2.isCyclic();
    // cout << std::boolalpha << ans2 << endl;

    // picture: https://www.youtube.com/watch?v=L0DcePeWHnM&list=PLEJXowNB4kPzByLnnFYNSCoqtFz0VKLk5&index=7
    return 0;
}

/*
true = there's cylce in a graph
false = there's no cylce in a graph
v=vertex,V=vertices(number of vertices),adj=adjacent
https://www.geeksforgeeks.org/detect-cycle-in-a-graph/#:~:text=Approach%3A%20Depth%20First%20Traversal%20can,the%20tree%20produced%20by%20DFS.

https://www.youtube.com/watch?v=uzVUw90ZFIg (best explanation)
Cycle Detection in Directed Graph using DFS

*/

Graph::Graph(int V){
    this->V = V;
    this->graph.resize(V);
    this->currVisited.resize(V);
    this->visitedVertex.resize(V);
}

void Graph::addEdge(int src,int dst){
    this->graph[src].push_back(dst);
}

void Graph::printAdjList(){
    for(int v=0; v<this->V; v++){
        printf("vertex %d",v);
        for(auto &adj : graph[v]){
            printf(" --> %d",adj);
        }
        cout << '\n';
    }
}
