#include <iostream>
#include <vector>
using std::cout;

class Graph{
private:
    std::vector<std::vector<int>> graph;
    int V;
public:
    Graph(int);
    void addEdgeU(int,int);
    void addEdge(int,int);
    void printGraph();

};


// Undi = UNDIrected
int main(){
    // pictorial representation: undirected.png
    Graph g(5);
    g.addEdgeU(0,1);
    g.addEdgeU(0,4);
    g.addEdgeU(1,2);
    g.addEdgeU(1,3);
    g.addEdgeU(1,4);
    g.addEdgeU(2,3);
    g.addEdgeU(3,4);

    g.printGraph();

    return 0;
}

Graph::Graph(int V){
    this->V = V;
    this->graph.resize(V);
}

void Graph::addEdgeU(int src,int dst){
    graph[src].push_back(dst);
    graph[dst].push_back(src);
}

void Graph::addEdge(int src,int dst){
    graph[src].push_back(dst);
}
void Graph::printGraph(){
    for(int vertex = 0; vertex < this->V; vertex++) {
        printf("\nvertex %d",vertex);
        for(auto &adj : graph[vertex]){
            printf(" --> %d",adj);
        }
        cout << '\n';
    }
}

/* resources

https://www.mathopenref.com/vertex.html (why vertex? what is vertex?)
https://www.geeksforgeeks.org/graph-and-its-representations/

https://stackoverflow.com/questions/28712364/difference-between-vector-int-v-and-vector-vectorint-v
https://www.geeksforgeeks.org/mathematics-graph-theory-basics-set-1/
https://www.tutorialspoint.com/graph_theory/graph_theory_fundamentals.htm
https://www.programiz.com/dsa/graph
https://www.geeksforgeeks.org/graph-implementation-using-stl-for-competitive-programming-set-1-dfs-of-unweighted-and-undirected/

https://www.youtube.com/watch?v=Cjk_VSNKJxE&list=PLeIMaH7i8JDiRA4fK9QmjvDSZKBJDyxpc&index=4
Adjecency List representation of graph (Code)

https://www.baeldung.com/cs/graphs

*/

/*
u-->v (directed)
u---v (undirected)


|something| = the size of "something"


Time: O(|E| + |V|)
Space: O(|E| + |V|)

*/
