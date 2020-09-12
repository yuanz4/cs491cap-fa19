#include <cstdio>
#include <vector>
#include <unordered_set>
#include <climits>
using namespace std;

int main() {
	int n, m, k;
	scanf("%d %d %d", &n, &m, &k);
	vector<vector<pair<int, int>>> d(n, vector<pair<int, int>>());
	int a, b, w;
	for (int i = 0; i < m; i++) {
		scanf("%d %d %d", &a, &b, &w);
		d[a-1].push_back({b-1, w});
		d[b-1].push_back({a-1, w});
	}
	unordered_set<int> s;
	for (int i = 0; i < k; i++) {
		scanf("%d", &a);
		s.insert(a-1);
	}
	int ret = INT_MAX;
	for (int i = 0; i < n; i++) {
		if (s.count(i)) {
			for (auto j: d[i]) {
				if (!s.count(j.first))
					ret = min(ret, j.second);
			}
		} else {
			for (auto j: d[i]) {
				if (s.count(j.first))
					ret = min(ret, j.second);
			}
		}
	}
	if (ret == INT_MAX)
		printf("-1\n");
	else
		printf("%d\n", ret);
	return 0;
}