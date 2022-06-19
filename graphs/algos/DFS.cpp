#include <iostream>
#include <vector>
#include <unordered_set>
#include <stack>
using std::cout;
using std::endl;

class Graph{
private:
    std::stack<int> S; // for dfs1
    std::unordered_set<int> visitedVertex; // for dfs2
    std::vector<bool> visitedVertex2; // for dfs3
    std::vector<std::vector<int>> graph;
    int vertices;

public:
    Graph(int V){
        this->vertices = V;
        this->graph.resize(V);
        this->visitedVertex2.resize(V,false); // for dfs 3
    }

    void addEdge(int src,int dst){
        this->graph[src].push_back(dst);
    }

    void addEdgeU(int src,int dst){
        this->graph[src].push_back(dst);
        this->graph[dst].push_back(src);
    }

    void printGraph(){
        for (int vertex = 0; vertex < this->vertices; vertex++) {
            printf("\nvertex %d",vertex);
            for(auto &adj : this->graph[vertex]){
                printf(" --> %d",adj);
            }
            cout << '\n';
        }
    }

    void dfs1(int start);
    void dfs2(int v);
    void dfs3(int v);
};

// iteratively using stack and set
void Graph::dfs1(int start){
    S.push(start);

    while(!S.empty()){
        int currVertex = S.top();
        S.pop();

        // if currVertex not in visited.
        if(this->visitedVertex.find(currVertex) == this->visitedVertex.end()){
            cout << currVertex << " ";
            this->visitedVertex.insert(currVertex);
        }

        // for each node find its adjacent
        for(auto &adj : this->graph[currVertex]){
            // if adj not in visited
            if(this->visitedVertex.find(adj) == this->visitedVertex.end()){
                S.push(adj);
            }

            // OR

            // I prefer below one even though it take addtional words to write.

            // // if adjacent in visitedVertex
            // if(this->visitedVertex.find(adj) != this->visitedVertex.end()){
            //     continue;
            // }
            // // else
            // S.push(adj);
        }
    }
    cout << endl;

    // empty the set after inserting some value, if needed
    this->visitedVertex.erase(visitedVertex.begin(),visitedVertex.end());
}

// recursively using set
void Graph::dfs2(int rootVertex){

    // to mark every node that has been visited
    visitedVertex.insert(rootVertex);

    // print visited node
    cout << rootVertex << " ";

    // traverse all the element such that adj to the current vertex
    for(auto &adj : this->graph[rootVertex]){

        // if adj not in visited, continue search
        if(visitedVertex.find(adj)==visitedVertex.end())
            dfs2(adj);
    }
}

// recursively using boolean array 
void Graph::dfs3(int rootVertex){
    // mark every node that has been visited
    visitedVertex2[rootVertex] = true;

    // print the element
    cout << rootVertex << " ";

    // for each node find its adjacent node
    for(int &adj : this->graph[rootVertex]){
    // for(auto &adj : this->graph[v]){

        // if current adjacent is not visited
        if(!visitedVertex2[adj])
            // dfs part
            dfs3(adj);
    }
}

int main(){
    // // picture: graph2.png
    // Graph graph = Graph(7);
    // graph.addEdge(0,1);graph.addEdge(0,3);graph.addEdge(1,0);graph.addEdge(1,2);graph.addEdge(1,3);graph.addEdge(1,5);graph.addEdge(1,6);graph.addEdge(2,3);graph.addEdge(2,1);graph.addEdge(2,5);graph.addEdge(2,4);graph.addEdge(3,0);graph.addEdge(3,2);graph.addEdge(3,4);graph.addEdge(4,3);graph.addEdge(4,2);graph.addEdge(4,6);graph.addEdge(5,1);graph.addEdge(5,2);graph.addEdge(6,1);graph.addEdge(6,4);

    // graph.printGraph();

    // graph.dfs1(0);

    // graph.dfs2(0);
    // cout << endl;

    // graph.dfs3(0);
    // cout << endl;


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
    // g.printGraph();
    // // g.dfs1(0);
    // // g.dfs2(0);
    // // cout << endl;
    // g.dfs3(0);

    // // picture: undirected.png
    // Graph g(5);
    // g.addEdgeU(0,1);
    // g.addEdgeU(0,4);
    // g.addEdgeU(1,2);
    // g.addEdgeU(1,3);
    // g.addEdgeU(1,4);
    // g.addEdgeU(2,3);
    // g.addEdgeU(3,4);
    // g.printGraph();

    // g.dfs1(0);
    // g.dfs2(0);
    // cout << endl;
    // g.dfs3(0);

    // // picture: directed.png
    // Graph g(5);
    // g.addEdge(0,1);
    // g.addEdge(1,2);
    // g.addEdge(2,3);
    // g.addEdge(3,4);
    // g.addEdge(4,0);
    // g.addEdge(4,1);

    // g.printGraph();
    // g.dfs3(0);

    // Graph g(6);
    // g.addEdge(5, 2);
    // g.addEdge(5, 0);
    // g.addEdge(4, 0);
    // g.addEdge(4, 1);
    // g.addEdge(2, 3);
    // g.addEdge(3, 1);
    // g.printGraph();
    // g.dfs3(5);

    return 0;
}


/*
TC: O(|V|+|E|)
SC: O(|V|), auxiliary array needed

description:
vertex==node
v=vertex
adj=adjacent
|V| = the number of vertices
|E| = the number of edges

https://www.youtube.com/watch?v=CvUMf8c2JFo&list=PLEJXowNB4kPzByLnnFYNSCoqtFz0VKLk5&index=3
video explanation for dfs3

https://www.youtube.com/watch?v=7fujbpJ0LB4&list=PLDV1Zeh2NRsDGO4--qE8yH72HFL1Km93P&index=4
video explanation for graph3

https://www.youtube.com/watch?v=TIbUeeksXcI
video explanation for graph2

https://www.youtube.com/watch?v=CvUMf8c2JFo

https://www.geeksforgeeks.org/depth-first-search-or-dfs-for-a-graph/?ref=leftbar-rightbar
code implementation

goals:
to print all vertex in dfs way

what we need:
stack,set

algo:
1.push vertex into stack
1.1. store vertex into a var so step 4 will work, because we need to pop stack before goes into step 4
2. pop stack
3. print top stack and push vertex into set to mark the vertex was already visited IF current vertex not in set.
4. find all the adjacent vertex (we need loops)
5. If some adjacent has been visited, then back to step 4 to looking for another adjacent
6.push vertex into stack
7.back to step 1 untill all nodes were printed

*/