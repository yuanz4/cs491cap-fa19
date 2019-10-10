#include <bits/stdc++.h>
using namespace std;

int dfsNumberCounter;

int dfs(vector<vector<int>>& server, vector<int>& low, vector<int>& num, int u, int parent) {
	int cur = dfsNumberCounter++;
	num[u] = cur;
	low[u] = cur;
	for (int v: server[u]) {
		if (v == parent)
			continue;
		int smaller;
		if (num[v] != -1)
			smaller = num[v];
		else
			smaller = dfs(server, low, num, v, u);
		low[u] = min(low[u], smaller);
	}
	return low[u];
}

bool cmp(pair<int, int> a, pair<int, int> b) {
	if (a.first < b.first)
		return true;
	else if (a.first > b.first)
		return false;
	else
		return a.second < b.second;
}

int main() {
	int n;
	while (~scanf("%d", &n)) {
		if (!n) {
			printf("0 critical links\n\n");
			continue;
		}
		vector<vector<int>> server(n, vector<int>());
		int cur, tmp, tmpp;
		for (int i = 0; i < n; i++) {
			scanf("%d (%d)", &cur, &tmp);
			for (int j = 0; j < tmp; j++) {
				scanf("%d", &tmpp);
				server[cur].push_back(tmpp);
			}
		}
		vector<int> low(n, -1), num(n, -1);
		dfsNumberCounter = 0;
		for (int u = 0; u < n; u++) {
			if (num[u] == -1)
				dfs(server, low, num, u, -1);
		}
		vector<pair<int, int>> ret;
		for (int u = 0; u < n; u++) {
			for (int v: server[u]) {
				if (num[u] < low[v])
					ret.push_back({min(u, v), max(u, v)});
			}
		}
		sort(ret.begin(), ret.end(), cmp);
		printf("%lu critical links\n", ret.size());
		for (int i = 0; i < ret.size(); i++)
			printf("%d - %d\n", ret[i].first, ret[i].second);
		printf("\n");
	}
	
	return 0;
}