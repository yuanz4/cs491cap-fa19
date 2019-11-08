#include <cstdio>
#include <vector>
#include <unordered_set>
#include <cstring>
using namespace std;

int n;
const int MX = 200+7;
int chaos[MX];
int type[MX];
unordered_set<int> adj[MX];

pair<int, int> dfs(int node, int kind) {
	pair<int, int> ret = {0, 0};
	type[node] = kind;
	if (kind == 0)
		ret.first++;
	else
		ret.second++;
	for (int i: adj[node]) {
		if (type[i] == -1) {
			pair<int, int> tmp = dfs(i, 1-kind);
			ret.first += tmp.first;
			ret.second += tmp.second;
		} else if (type[i] == kind)
			chaos[node] = 1;
	}
	if (chaos[node]) {
		for (int i: adj[node])
			chaos[i] = 1;
		return {0, 0};
	}
	return ret;
}

int main() {
	int test;
	scanf("%d", &test);
	while (test--) {
		scanf("%d", &n);
		int enemy, cur;
		for (int i = 0; i < n; i++)
			adj[i].clear();
		for (int i = 0; i < n; i++) {
			scanf("%d", &enemy);
			for (int j = 0; j < enemy; j++) {
				scanf("%d", &cur);
				cur--;
				if (cur >= n)
					continue;
				adj[i].insert(cur);
				adj[cur].insert(i);
			}
		}
		memset(type, -1, sizeof type);
		memset(chaos, 0, sizeof chaos);
		int ret = 0;
		for (int i = 0; i < n; i++) {
			if (type[i] == -1) {
				pair<int, int> cur = dfs(i, 0);
				if (chaos[i])
					continue;
				if (!cur.first || !cur.second)
					ret++;
				else
					ret += max(cur.first, cur.second);
			}
		}
		// for (int i = 0; i < n; i++)
		// 	printf("%d ", chaos[i]);
		// printf("\n");
		printf("%d\n", ret);
	}
	return 0;
}