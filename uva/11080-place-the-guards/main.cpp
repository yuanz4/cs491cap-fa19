#include <bits/stdc++.h>
using namespace std;

bool bipartite;

pair<int, int> dfs(vector<vector<int>>& adj, vector<int>& type, int node, int kind) {
	pair<int, int> ret = {0, 0};
	type[node] = kind;
	if (kind == 0)
		ret.first++;
	else
		ret.second++;
	for (int i: adj[node]) {
		if (bipartite == false)
			break;
		if (type[i] == -1) {
			pair<int, int> tmp = dfs(adj, type, i, 1-kind);
			ret.first += tmp.first;
			ret.second += tmp.second;
		} else if (type[i] == kind)
			bipartite = false;
	}
	return ret;
}

int main() {
	int test;
	scanf("%d", &test);
	int junc, street;
	while (test--) {
		scanf("%d %d", &junc, &street);
		int one = 0, two = 0;
		vector<vector<int>> adj(junc, vector<int>());
		int a, b;
		for (int i = 0; i < street; i++) {
			scanf("%d %d", &a, &b);
			adj[a].push_back(b);
			adj[b].push_back(a);
		}
		vector<int> type(junc, -1);
		bipartite = true;
		int ret = 0;
		for (int i = 0; i < junc; i++) {
			if (type[i] == -1) {
				pair<int, int> cur = dfs(adj, type, i, 0);
				if (!cur.first || !cur.second)
					ret++;
				else
					ret += min(cur.first, cur.second);
			}
		}
		if (!bipartite)
			printf("-1\n");
		else
			printf("%d\n", ret);
	}
	return 0;
}