#include<iostream>
#include<vector>

using namespace std;

/*
	@DravitLochan
*/

class Graph{
	
	public:
	int size;
	vector< vector<int> > adjecency_list;
	
	Graph(int size) {
		this->size = size;
		adjecency_list.resize(size);
	}
	
	void addEdge(int v1, int v2) {
		this->adjecency_list[v1].push_back(v2);
	}
	
};

int main() {

	int size;
	cin>>size;
	Graph g = Graph(size);
	g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);
	return 0;

}

