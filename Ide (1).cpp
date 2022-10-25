// Program to find Dijkstra's shortest path using
// priority_queue in STL
//Given a graph and a source vertex in graph, find shortest paths from source to all vertices in the given graph.


#include <bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f

class graph {
    int V;
    vector<pair<int, int> > * adj;
    public:
    graph(int V);
    void add_edge(int u , int v , int w);
    
    void shortest_path_weighted_undirected_graph(int src);
};
 graph:: graph(int V) {
     
     this->V = V;
     this -> adj = new vector<pair<int, int>> [V];
 }

void graph:: add_edge( int u , int v , int w)
{
    adj[u].push_back(make_pair(v, w));
	adj[v].push_back(make_pair(u, w));
}

void graph:: shortest_path_weighted_undirected_graph(int src)
{
 	priority_queue<pair<int, int>, vector<pair<int,int>>, greater<pair<int, int>>> pq;   
 	vector<int> dist(V, INF);
    pq.push(make_pair(0, src));
	dist[src] = 0;
	
	while (!pq.empty()) {
	
		int u = pq.top().second;
		pq.pop();

	
		for (auto x : adj[u]) {
			int v = x.first;
			int weight = x.second;

			if (dist[v] > dist[u] + weight) {
				dist[v] = dist[u] + weight;
				pq.push(make_pair(dist[v], v));
			}
		}
	}

	// Print shortest distances stored in dist[]
	printf("Vertex Distance from Source\n");
	for (int i = 0; i < V; ++i)
		printf("%d \t\t %d\n", i, dist[i]);

}

int main() {
	
	graph g(9);

	// making above shown graph
		g.add_edge(0, 1, 4);
		g.add_edge(0, 7, 8);
		g.add_edge(1, 2, 8);
		g.add_edge(1, 7, 11);
		g.add_edge(2, 3, 7);
		g.add_edge(2, 8, 2);
		g.add_edge(2, 5, 4);
		g.add_edge(3, 4, 9);
		g.add_edge(3, 5, 14);
		g.add_edge(4, 5, 10);
		g.add_edge(5, 6, 2);
		g.add_edge(6, 7, 1);
		g.add_edge(6, 8, 6);
		g.add_edge(7, 8, 7);

 g.shortest_path_weighted_undirected_graph(0);
}

// Result
// Vertex Distance from Source
// 0 		 0
// 1 		 4
// 2 		 12
// 3 		 19
// 4 		 21
// 5 		 11
// 6 		 9
// 7 		 8
// 8 		 14
