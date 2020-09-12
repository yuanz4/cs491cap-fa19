#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> ii;
typedef vector<ii> vii;
const int MX = 1000+7;
int connect[MX], state[MX];

double cal(pair<int, int>& x, pair<int, int>& y) {
	return sqrt(pow(x.first-y.first, 2)+pow(x.second-y.second, 2));
}

int find_connect(int a) {
	if (connect[a] != a)
		return connect[a] = find_connect(connect[a]);
	return a;
}

bool same_connect(int a, int b) {
	if (find_connect(a) == find_connect(b))
		return true;
	return false;
}

void join_connect(int a, int b) {
	connect[find_connect(a)] = find_connect(b);
}

int find_state(int a) {
	if (state[a] != a)
		return state[a] = find_state(state[a]);
	return a;
}

bool same_state(int a, int b) {
	if (find_state(a) == find_state(b))
		return true;
	return false;
}

void join_state(int a, int b) {
	state[find_state(a)] = find_state(b);
}

int main() {
	int test;
	scanf("%d", &test);
	for (int t = 1; t <= test; t++) {
		int n, r;
		scanf("%d %d", &n, &r);
		int x, y;
		vii xy;
		for (int i = 0; i < n; i++) {
			scanf("%d %d", &x, &y);
			xy.push_back({x, y});
			connect[i] = i;
			state[i] = i;
		}
		vector<pair<double, ii>> dist;
		for (int i = 0; i < n; i++) {
			for (int j = i+1; j < n; j++) {
				dist.push_back({cal(xy[i], xy[j]), {i, j}});
			}
		}
		sort(dist.begin(), dist.end());
		int edge = 0;
		double road = 0, railroad = 0;
		int a, b;
		for (int i = 0; i < dist.size(); i++) {
			if (edge == n-1)
				break;
			double weight = dist[i].first;
			a = dist[i].second.first;
			b = dist[i].second.second;
			if (!same_connect(a, b)) { // not connected yet
				join_connect(a, b);
				edge++;
				if (weight <= r) { // same state
					road += weight;
					if (!same_state(a, b))
						join_state(a, b);
				} else { // different state
					railroad += weight;
				}
			}
		}
		int total = 0;
		unordered_set<int> all_state;
		for (int i = 0; i < n; i++) {
			int cur = find_state(i);
			if (!all_state.count(cur)) {
				all_state.insert(cur);
				total++;
			}
		}
		printf("Case #%d: %d %d %d\n", t, total, int(round(road)), int(round(railroad)));
	}
	return 0;
}