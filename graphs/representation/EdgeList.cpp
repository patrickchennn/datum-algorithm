#include <iostream>
#include <vector>
#include <utility> // for pair
using std::cout;
using std::endl;

class Graph{
private:
    std::vector<std::pair<int,int>> edgeList;
public:
    Graph(){
    }

    void addList(int src,int dst){
        this->edgeList.push_back({src,dst});
    }

    void printEL(){
        cout << "[";
        for(int i=0; i<this->edgeList.size(); i++){
            printf("(%d,%d)",this->edgeList[i].first, this->edgeList[i].second);
        }
        puts("]");
    }

};

int main(){
    Graph g;

    g.addList(1,2);
    g.addList(1,3);
    g.addList(2,3);

    g.printEL();
    return 0;
}

/*
https://leetcode.com/problems/redundant-connection/
*/