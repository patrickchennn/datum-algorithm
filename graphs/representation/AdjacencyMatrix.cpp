#include <iostream>
#include <vector>
#include <climits>
using std::cout;

class Graph{
private:
    int V;
    std::vector<std::vector<bool>> graph;

public:
    Graph(int inputVertices){
        this->V = inputVertices;
        this->graph.resize(inputVertices);

        for(int row=0; row<this->V; row++){
            for(int col=0; col<this->V; col++){
                graph[row].push_back(false);
            }
        }
    }

    // add edge undirected
    void addEdgeUndi(int src,int dst){
        this->graph[src][dst] = 1;

        // since this is a undirected graph (ab=ba)
        this->graph[dst][src] = 1;
    }
    void addEdgeDi(int src,int dst){
        this->graph[src][dst] = 1;
    }
    void removeEdege(int src,int dst){
        this->graph[src][dst] = 0;
        this->graph[dst][src] = 0;
    }

    void printGraph() {
        for (int row=0; row<this->V; row++){
            cout << row << " : ";
            for (int col=0; col<this->V; col++){
                cout << graph[row][col] << " ";
            }
            cout << "\n";
        }
    }

};

class weightedGraph{
// suppose 0 = null
private:
    int V;
    std::vector<std::vector<int>> graph;
public:
    weightedGraph(int inputVertices){
        this->V = inputVertices;
        this->graph.resize(inputVertices);

        for(int row=0; row<this->V; row++){
            for(int col=0; col<this->V; col++){
                this->graph[row].push_back(0);
            }
        }
    }
    // add edge undirected
    void addEdgeUndi(int src,int dst,int weight){
        this->graph[src][dst] = weight;

        // since this is a undirected graph (ab=ba)
        this->graph[dst][src] = weight;
    }
    void addEdgeDi(int src,int dst,int weight){
        this->graph[src][dst] = weight;
    }
    void removeEdege(int src,int dst){
        this->graph[src][dst] = 0;
        this->graph[dst][src] = 0;
    }

    void printGraph() {
        for (int row=0; row<this->V; row++){
            cout << row << " : ";
            for (int col=0; col<this->V; col++){
                cout << graph[row][col] << " ";
            }
            cout << "\n";
        }
    }
};

int main(){
    // // visual representation: adjacency-matrix.png
    Graph g1(5);

    g1.addEdgeUndi(0,1);
    g1.addEdgeUndi(0,4);
    g1.addEdgeUndi(1,2);
    g1.addEdgeUndi(1,3);
    g1.addEdgeUndi(1,4);
    g1.addEdgeUndi(2,3);
    g1.addEdgeUndi(3,4);

    g1.printGraph();
    puts("----------------------");
    weightedGraph g2(5);
    g2.addEdgeUndi(0,1,3);
    g2.addEdgeUndi(0,4,2);
    g2.addEdgeUndi(1,2,9);
    g2.addEdgeUndi(1,3,10);
    g2.addEdgeUndi(1,4,5);
    g2.addEdgeUndi(2,3,15);
    g2.addEdgeUndi(3,4,6);

    g2.printGraph();
    
    return 0;
}

/*
https://www.programiz.com/dsa/graph-adjacency-matrix
*/