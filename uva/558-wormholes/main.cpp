#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
const int INF = 0x3f3f3f3f;

int main() {
	int test;
	scanf("%d", &test);
	while (test--) {
		int V, E;
		scanf("%d %d", &V, &E);
		int x, y, t;
		vector<vii> AdjList(V, vii());
		for (int i = 0; i < E; i++) {
			scanf("%d %d %d", &x, &y, &t);
			AdjList[x].push_back({y, t});
		}
		vi dist(V, INF);
		dist[0] = 0;
		for (int i = 0; i < V - 1; i++) { // relax all E edges V-1 times
			for (int u = 0; u < V; u++) { // these two loops = O(E), overall O(VE)
				for (int j = 0; j < (int)AdjList[u].size(); j++) {
					ii v = AdjList[u][j]; // record SP spanning here if needed
					dist[v.first] = min(dist[v.first], dist[u] + v.second); // relax
				}
			}
		}
		bool hasNegativeCycle = false;
		for (int u = 0; u < V; u++) { // one more pass to check
			for (int j = 0; j < (int)AdjList[u].size(); j++) {
				ii v = AdjList[u][j];
				if (dist[v.first] > dist[u] + v.second) // if this is still possible
					hasNegativeCycle = true; // then negative cycle exists!
			}
		}
		printf("%s\n", hasNegativeCycle ? "possible" : "not possible");
	}
	return 0;
}