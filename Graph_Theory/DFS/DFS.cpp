#include<iostream>
#include<vector>
#include <algorithm>

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
		for(int i = 0; i < v; ++i){
			adjecency_list[i].push_back(i);
		}
	}
	
		// undirected graph, so insert twice
		
	void addEdge(int v1, int v2) {
		this->adjecency_list[v1].push_back(v2);
		this->adjecency_list[v2].push_back(v1);
	}
	
	void dfsTraversal(int vertice, vector<int> visited) {
		// cout<<visited[vertice];
		if(!visited[vertice]) {
			// cout<<vertice<<"\n";
			visited[vertice] = 1;
			for(int a = 0; a < adjecency_list[vertice].size(); ++a) {
				if(!visited[a]) {
					cout<<a<<"\n";
					dfsTraversal(a, visited);
				}
			}
		}
	}
	
};

int main() {
	
	int v, e, i, v1, v2;
	cout<<"enter number of vertices \n";
	cin>>v;
	vector<int> visited(v, 0);
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
	// cout<<visited[0];
	g.dfsTraversal(0, visited);
	return 0;

}

