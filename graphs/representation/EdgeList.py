from typing import List

class Graph:
    def __init__(self) -> None:
        self.edges = []

    def addEdge(self, src:int ,dst: int) -> None:
        self.edges.append([src,dst])

    def printGraph(self) -> None:
        print("[",end="")

        for (src,dst) in self.edges:
            print(f"[{src},{dst}]",end="")
        print("]")

    def getNode(self,index: int) -> List:
        return self.edges[index]


def main():
    g = Graph()

    g.addEdge(1,2)
    g.addEdge(1,3)
    g.addEdge(2,3)

    g.printGraph()
    print(g.getNode(0))

if __name__ == "__main__":
	main()


'''
graph picture:
https://leetcode.com/problems/redundant-connection/
'''