#include <cstdio>
#include <queue>
#include <vector>
#include <unordered_map>
using namespace std;

typedef vector<int> vi;
typedef pair<int, int> ii;
const int INF = 0x3f3f3f3f;

int N, M, s, t, p;

void dijkstra(unordered_map<int, unordered_map<int, int>>& adjList, unordered_map<int, int>& dist, int start) {
	dist[start] = 0;
	priority_queue<ii, vector<ii>, greater<ii>> pq;
	pq.push(ii(0, start));
	while (!pq.empty()) {
		ii front = pq.top();
		pq.pop();
		int d = front.first, u = front.second;
		if (d > dist[u])
			continue;
		for (auto& v: adjList[u]) {
			if (dist[u] + v.second < dist[v.first]) {
				dist[v.first] = dist[u] + v.second;
				pq.push(ii(dist[v.first], v.first));
			}
		}
	}
}

int main() {
	int test;
	scanf("%d", &test);
	while (test--) {
		scanf("%d %d %d %d %d", &N, &M, &s, &t, &p);
		int u, v, c;
		unordered_map<int, unordered_map<int, int>> adjList, iadjList;
		vector<ii> edge;
		for (int i = 0; i < M; i++) {
			scanf("%d %d %d", &u, &v, &c);
			edge.push_back({u, v});
			adjList[u][v] = c;
			iadjList[v][u] = c;
		}
		unordered_map<int, int> dist, idist;
		for (int i = 1; i <= N; i++) {
			dist[i] = INF;
			idist[i] = INF;
		}
		dijkstra(adjList, dist, s);
		dijkstra(iadjList, idist, t);
		int ret = -1;
		for (ii pa: edge) {
			u = pa.first, v = pa.second;
			c = adjList[u][v];
			if (dist[u] + c + idist[v] <= p)
				ret = max(ret, c);
		}
		printf("%d\n", ret);
	}
	return 0;
}