from collections import defaultdict
# This class represents a directed graph using
# adjacency list representation
 
class Graph:
    def __init__(self) -> None:
        self.visitedVertex = set() # empty set
        self.graph = defaultdict(list)
 
    # Utility function to add an edge(undirected) to a graph
    def addEdgeUndi(self, src, dst) -> None:
        self.graph[src].append(dst)
        self.graph[dst].append(src)
 
    def dfs(self, v: int) -> None:
        # to mark every node that has been visited
        self.visitedVertex.add(v)
        print(v,end=" ")

        # for each node find its adjacent
        for adj in self.graph[v]:
            if(adj not in self.visitedVertex):
                self.dfs(adj)
 
# Driver code
def main():
    # # picture: undirected.png
    # g = Graph()
    # g.addEdgeUndi(0,1)
    # g.addEdgeUndi(0,4)
    # g.addEdgeUndi(1,2)
    # g.addEdgeUndi(1,3)
    # g.addEdgeUndi(1,4)
    # g.addEdgeUndi(2,3)
    # g.addEdgeUndi(3,4)
    # g.dfs(0)

    
    # picture: graph3.png
    g = Graph()
    g.addEdgeUndi(0,1)
    g.addEdgeUndi(0,9)
    g.addEdgeUndi(1,8)
    g.addEdgeUndi(9,8)
    g.addEdgeUndi(8,7)
    g.addEdgeUndi(7,10) # r2
    g.addEdgeUndi(7,11) # r1
    g.addEdgeUndi(7,3) # rx
    g.addEdgeUndi(10,11)
    g.addEdgeUndi(11,7) # r1
    g.addEdgeUndi(11,10) # r2
    g.addEdgeUndi(6,7)
    g.addEdgeUndi(6,5) #r2
    g.addEdgeUndi(5,6) # r3
    g.addEdgeUndi(5,3) # r4
    g.addEdgeUndi(3,7) # rx
    g.addEdgeUndi(3,5) # r4
    g.addEdgeUndi(3,2)
    g.addEdgeUndi(3,4)
    g.dfs(0)

if __name__ == "__main__":
	main()
 