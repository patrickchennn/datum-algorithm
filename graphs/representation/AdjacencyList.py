from typing import List

# Like linked list
class AdjNode:
    def __init__(self, value: int) -> None:
        self.vertex: int = value
        self.next = None

class Graph:
    def __init__(self,vertices: int) -> None:
        self.vertices: int = vertices
        self.graph: List = [None] * vertices

    def addEdge(self, src: int, dst: int) -> None:
        # adding the node to the source node
        node = AdjNode(dst)
        node.next = self.graph[src]
        self.graph[src] = node

        # adding the src node to the dst as it is the undirected graph
        node = AdjNode(src)
        node.next = self.graph[dst]
        self.graph[dst] = node

    def printGraph(self) -> None:

        for vertex in range(self.vertices):
            print(f"Adjacency list of vertex {vertex}\n head", end="")
            temp = self.graph[vertex]
            
            while temp:
                print(f" -> {temp.vertex}", end="")
                temp = temp.next
            print("\n")

def main():
    vertices: int = 5

    graph = Graph(vertices)
    graph.addEdge(0,1)
    graph.addEdge(0,4)
    graph.addEdge(1,2)
    graph.addEdge(1,3)
    graph.addEdge(1,4)
    graph.addEdge(2,3)
    graph.addEdge(3,4)
    
    graph.printGraph()

if __name__ == "__main__":
	main()
