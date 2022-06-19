#include <iostream>
#include <vector>
using std::cout;
using std::endl;
using std::vector;

class DSU{
private:
	vector<int> parent;
public:
	DSU(){
		// picture: graph1.png (in this directory)
		parent = {-3,0,5,0,3,-2};
	}
	void print(){
		for(int &data : parent)
			cout << data << " ";
		cout << '\n';
	}

	int findParent(int vertex){
		// // iteratively
		// while(this->parent[vertex] > -1){
		// 	vertex = this->parent[vertex];
		// 	printf("vertex=%d\n",vertex);
		// }
		// return vertex;

		// recursively
		if(parent[vertex] < 0)
			return vertex;

		return findParent(parent[vertex]);

	}
	int sizeGraph(int vertex){
		if(parent[vertex] < 0)
			return abs(parent[vertex]);
		return sizeGraph(parent[vertex]);

	}
	void unionGraph(int data1,int data2){
		int parent1 = findParent(data1);
		int parent2 = findParent(data2);

		if(parent1==parent2)
			puts("There is a cycle in this graph--ew");
		
		
		// same stuffs. Depends on you which graph you wanted to be the child. 
		// Is it graph 2 to be the parent of graph 1 (no 1) or graph 1 to be the parent of graph 2 (no 2)?

		// this->parent[parent1] = parent2; // no 1
		// this->parent[parent1] -= 1;

		this->parent[parent2] = parent1; // no 2
		this->parent[parent1] -= 1;
	}
};

int main(){
	DSU test;
	test.print();

	cout << test.findParent(4) << endl;
	cout << test.sizeGraph(4) << endl;
	cout << test.findParent(2) << endl;

	// test.unionGraph(4,2);
	// test.print();
	return 0;
}

/*
Make sure to watch the video because it will be confusing by just looking at the code.

arr1 = 
-3,0,5,0,3,-2
0,1,2,3,4,5 --> the indices are representing the vertices(nodes)

https://www.youtube.com/watch?v=ayW5B2W9hfo
Union Find in 5 minutes — Data Structures & Algorithms
*/