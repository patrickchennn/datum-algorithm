#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>
using std::cout;
using std::endl;

class Graph{
private:
    std::queue<int> Q;
    std::unordered_set<int> visitedVertex;
    std::vector<bool> visitedVertex2;
    std::vector<std::vector<int>> graph;
    int V;

public:
    Graph(int vertices){
        this->V = vertices;
        this->graph.resize(vertices);
        this->visitedVertex2.resize(vertices,0);
    }

    // Directed edge src-->dst
    void addEdge(int src,int dst){
        this->graph[src].push_back(dst);
    }

    // Undirected edge src<-->dst
    void addEdgeU(int src,int dst){
        this->graph[src].push_back(dst);
        this->graph[dst].push_back(src);
    }

    void printGraph(){
        for (int vertex = 0; vertex < this->V; vertex++) {
            printf("\nAdjacency list of vertex %d\n",vertex);
            cout << "head";
            for(auto &adj : this->graph[vertex]){
                printf(" --> %d",adj);
            }
            cout << '\n';
        }
    }

    void bfs(int root);
    void bfs2(int root);
    // using boolean array
    void bfs3(int root);
};

void Graph::bfs(int root){
    std::queue<int> Q;
    std::unordered_set<int> visitedVertex;
    Q.push(root);

    while(!Q.empty()){
        int currVertex = Q.front();
        cout << currVertex << " ";
        visitedVertex.insert(currVertex);
        Q.pop(); // dequeue(pop the element)

        /* 
        get all adjacent vertices of the dequeued vertex.
        If a adjacent has not been visited, mark it visited and enqueue(push the element) it
        */
        for(auto &adj : this->graph[currVertex]){
            
            // // if adjacent in visitedVertex
            // if(visitedVertex.find(adj) != visitedVertex.end()){
            //     continue;
            // }
            // // if not
            // Q.push(adj);
            // visitedVertex.insert(adj);

            // actually, you can immediatly check the adjacent has not been visited or not, but above code is easier to understand, I suppose?

            // if adjacent not in visitedVertex
            if(visitedVertex.find(adj) == visitedVertex.end()){
                // then push the adj into the queue
                Q.push(adj);
                // and mark it as true(visited)
                visitedVertex.insert(adj);
            }
        }
    }
    cout << endl;
}

void Graph::bfs2(int root){
    Q.push(root);

    while(!Q.empty()){
        int currVertex = Q.front();

        // Q.pop() can be placed at the end
        // Q.pop();

        // if currVertex not in visitedVertex
        if(visitedVertex.find(currVertex) == visitedVertex.end()){
            cout << currVertex << " ";
            visitedVertex.insert(currVertex);
        }

        // for each each node find its adjacent
        for(auto &adj : graph[currVertex]){
            // if adjacent is not in visitedVertex
            if(visitedVertex.find(adj) == visitedVertex.end()){
                Q.push(adj);
            }
        }

        Q.pop();
    }
    cout << endl;
}

int main(){

    // // picture: graph2.png
    // Graph g(7);
    // g.addEdge(0,1);g.addEdge(0,3);g.addEdge(1,0);g.addEdge(1,2);g.addEdge(1,3);g.addEdge(1,5);g.addEdge(1,6);g.addEdge(2,3);g.addEdge(2,1);g.addEdge(2,5);g.addEdge(2,4);g.addEdge(3,0);g.addEdge(3,2);g.addEdge(3,4);g.addEdge(4,3);g.addEdge(4,2);g.addEdge(4,6);g.addEdge(5,1);g.addEdge(5,2);g.addEdge(6,1);g.addEdge(6,4);

    // g.printGraph();
    // g.bfs(0); // 0 1 3 2 5 6 4
    // // g.bfs2(0); // 0 1 3 2 5 6 4

    // // graph no.2
    // Graph g(4);
    // g.addEdge(0, 1);
    // g.addEdge(0, 2);
    // g.addEdge(1, 2);
    // g.addEdge(2, 0);
    // g.addEdge(2, 3);
    // g.addEdge(3, 3);
    // g.printGraph();
    // g.bfs(2); // 2 0 3 1
    // // g.bfs2(2); // 2 0 3 1


    // // picture: graph3.png
    // Graph g = Graph(12);
    // g.addEdgeU(0,1);
    // g.addEdgeU(0,9);
    // g.addEdgeU(1,8);
    // g.addEdgeU(9,8);
    // g.addEdgeU(8,7);
    // g.addEdgeU(7,10);
    // g.addEdgeU(10,11);
    // g.addEdgeU(11,7);
    // g.addEdgeU(7,6);
    // g.addEdgeU(6,5);
    // g.addEdgeU(5,3);
    // g.addEdgeU(7,3);
    // g.addEdgeU(3,2);
    // g.addEdgeU(3,4);
    // g.bfs(0);
    // // g.bfs2(0);

    // // picture: graph5.png

    Graph g(13);
    g.addEdgeU(10,1);
    g.addEdgeU(10,9);
    g.addEdgeU(1,8);
    g.addEdgeU(9,8);
    g.addEdgeU(8,12);
    g.addEdgeU(12,2);
    g.addEdgeU(2,3);
    g.addEdgeU(3,4);
    g.addEdgeU(9,0);
    g.addEdgeU(0,7);
    g.addEdgeU(0,11);
    g.addEdgeU(7,3);
    g.addEdgeU(7,6);
    g.addEdgeU(7,11);
    g.addEdgeU(6,5);
    g.printGraph();
    g.bfs(0);
    g.bfs2(0);
    return 0;
}

/*
https://www.youtube.com/watch?v=TIbUeeksXcI
Depth First & Breadth First Graph Search - DFS & BFS Graph Searching Algorithms

goals:
To print all vertex in bfs way

what we need: 
queue,set(to check if particular vertex has been visited or not)

algorithm:
1.push vertex into queue
2.print it
3.push vertex into set(to mark it as already visited vertex)
4.deque/pop vertex
5. find "all" the adjacent vertex (we need loops since we need to find all the adjacent vertex)
5.1. if adjacent vertex is already vistied, don't push into queue/skip/continue.
5.1. else insert data into queue and push data into set to mark it as visited vertex
6. go step 1 untill all vertex has been printed (while loops)

*/