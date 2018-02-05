#include<iostream>
#include<vector>

using namespace std;

/*
	@DravitLochan
*/

class Graph{
	
	public:
	int v, e;
	vector< vector<int> > adjecency_list;
	
	Graph(int v, int e) {
		this->v = v;
		this->e = e;
		adjecency_list.resize(v);
	}
	
		// undirected graph, so insert twice
		
	void addEdge(int v1, int v2) {
		this->adjecency_list[v1].push_back(v2);
		this->adjecency_list[v2].push_back(v1);
	}
	
};

int main() {

	int v, e, i, v1, v2;
	cout<<"enter number of vertices \n";
	cin>>v;
    cout<<"enter number of edges \n";
    cin>>e;
    Graph g = Graph(v, e);
    i = 0;
    cout<<"Enter vertices in pair for an edge \n";
    while(i<e) {
    	cin>>v1>>v2;
    	g.addEdge(v1, v2);
    	++i;
	}
	
	return 0;

}

