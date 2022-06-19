#include <iostream>
#include <vector>
#include <utility> // for pair
#include <numeric> // for iota
using std::cout;
using std::endl;

class DSU{
private:
    std::vector<int> parent;
public:
    DSU(int V){
        this->parent.resize(V+1,-1);
    }

    void printVector1d(std::vector<int> &arr){
        for(int &element : arr)
            cout << element << " ";
        cout << "\n\n";
    }
    
    int findParent(int vertex){
        /*
        p = >0 = 1 2 3 ... ∞
        q = !(p) = -1 -2 -3 ... -∞
        r = <0 = -1 -2 -3 ... -∞
        q==r --> true
        */
        while(this->parent[vertex] > -1){
            vertex = this->parent[vertex];
        }
        return vertex;
    }
    
    bool unionGraph(int data1,int data2){
        int parent1 = this->findParent(data1);
        int parent2 = this->findParent(data2);

        // if graph contain cylce
        if(parent1 == parent2)
            return true;

        // if not then perform union. It means there is not cycle also
        this->parent[parent2] = parent1;

        printf("(%d,%d)\n",data1,data2);
        printf("(%d,%d)\n",parent1,parent2);
        // this->parent[parent1] -= 1;
        this->printVector1d(this->parent);
        return false;
    }
};

class Graph{
private:
    std::vector<std::pair<int,int>> edgeList;
    int V;
public:
    Graph(int V){
        this->V = V;
    }
    void addList(int src,int dst){
        edgeList.push_back({src,dst});
    }

    void isCylic(){
        DSU dsu(this->V);

        // for(std::pair<int, int> &edge : this->edgeList){
        for(auto &edge : this->edgeList){
            if(dsu.unionGraph(edge.first, edge.second)){
                printf("Cycle at: (%d,%d)\n",edge.first,edge.second);
                return;
            }
        }
        puts("no cycle");
    }

    void printEL(){
        cout << "[";
        for(int i=0; i<edgeList.size(); i++){
            printf("(%d,%d)",edgeList[i].first, edgeList[i].second);
        }
        puts("]");
    }
};

int main(){
    // Graph g1(3+1);

    // g1.addList(1,2);
    // g1.addList(1,3);
    // g1.addList(2,3);

    // g1.printEL();
    // g1.isCylic();

    Graph g2(8);
    g2.addList(1,2);
    g2.addList(3,4);
    g2.addList(5,6);
    g2.addList(7,8);
    g2.addList(2,4);
    g2.addList(2,5);
    g2.addList(1,3);
    g2.addList(6,8);
    g2.addList(5,7);

    g2.printEL();
    g2.isCylic();
    return 0;
}

/*
https://leetcode.com/problems/redundant-connection/

https://www.youtube.com/watch?v=wU6udHRIkcc&t=457s explanation for g2
1.12 Disjoint Sets Data Structure - Weighted Union and Collapsing Find
*/