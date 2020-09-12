#include <bits/stdc++.h>
using namespace std;

bool bipartite;

void bfs(vector<vector<int>>& adj, vector<int>& type, int node, int kind) {
	type[node] = kind;
	for (int i: adj[node]) {
		if (!bipartite)
			break;
		if (type[i] == -1)
			bfs(adj, type, i, 1-kind);
		else if (type[i] == kind)
			bipartite = false;
	}
}

int main() {
	int n;
	while (scanf("%d", &n), n) {
		vector<vector<int>> adj(n, vector<int>());
		int a, b;
		while (scanf("%d %d", &a, &b), a) {
			a--, b--;
			adj[a].push_back(b);
			adj[b].push_back(a);
		}
		vector<int> type(n, -1);
		bipartite = true;
		for (int i = 0; i < n; i++) {
			if (type[i] == -1)
				bfs(adj, type, i, 0);
		}
		if (bipartite)
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}