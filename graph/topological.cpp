#include <bits/stdc++.h>
using namespace std;


	//Function to return list containing vertices in Topological order.
	void topoSort(int V, vector<int> adj[])
	{
		int indegree[V] = {0};
		for (int i = 0; i < V; i++) {
			for (auto it : adj[i]) {
				indegree[it]++;
			}
		}

		queue<int> q;
		for (int i = 0; i < V; i++) {
			if (indegree[i] == 0) {
				q.push(i);
			}
		}
		vector<int> topo;
		while (!q.empty()) {
			int node = q.front();
			q.pop();
			topo.push_back(node);
			// node is in your topo sort
			// so please remove it from the indegree

			for (auto it : adj[node]) {
				indegree[it]--;
				if (indegree[it] == 0) q.push(it);
			}
		}

		for(auto i:topo){
			cout<<i;
			cout<<endl;
		}
	}



int main() {

	vector<int> adj[6] = {{}, {0}, {1}, {0,2}, {2, 3}, {}};
	int V = 6;
	topoSort(V, adj);


	return 0;
}