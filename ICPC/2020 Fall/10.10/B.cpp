#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<pair<int, int>> vii;
const int MAX = 1e5+7;

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(0);
	int n, m, k;
	cin >> n >> m >> k;
	vector<vii> adj(n, vii());
	for (int i = 0; i < m; i++) {
		int u, v, l;
		cin >> u >> v >> l;
		adj[u-1].push_back({v-1, l});
		adj[v-1].push_back({u-1, l});
	}
	int ans = INT_MAX;
	unordered_set<int> flour;
	for (int i = 0; i < k; i++) {
		int a;
		cin >> a;
		flour.insert(a-1);
	}
	for (int i: flour) {
		for (auto j: adj[i]) {
			if (!flour.count(j.first))
				ans = min(ans, j.second);
		}
	}
	if (ans == INT_MAX)
		cout << -1 << '\n';
	else
		cout << ans << '\n';
	return 0;
}