#include <cstdio>
#include <queue>
#include <vector>
#include <unordered_map>
using namespace std;

typedef vector<int> vi;
typedef pair<int, int> ii;
const int INF = 0x3f3f3f3f;

int n, k;
vi cost;
vector<vi> t;
unordered_map<int, unordered_map<int, int>> adjList;
unordered_map<int, int> dist;

void dijkstra() {
	dist[0] = 0;
	priority_queue<ii, vector<ii>, greater<ii>> pq;
	pq.push(ii(0, 0));
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
	while (~scanf("%d %d", &n, &k)) {
		cost.assign(n, 0);
		for (int i = 0; i < n; i++)
			scanf("%d", &cost[i]);
		t.assign(n, vi());
		adjList.clear();
		dist.clear();
		int tmp;
		char c;
		for (int i = 0; i < n; i++) {
			while (1) {
				scanf("%d%c", &tmp, &c);
				t[i].push_back(tmp);
				if (c != ' ')
					break;
			}
			for (int j = 1; j < t[i].size(); j++) {
				int index1, index2;
				if (t[i][j-1])
					index1 = i*100+t[i][j-1];
				else
					index1 = t[i][j-1];
				index2 = i*100+t[i][j];
				adjList[index1][index2] = adjList[index2][index1] = cost[i]*(t[i][j]-t[i][j-1]);
			}
			for (int j = 0; j < t[i].size(); j++) {
				dist[i*100+t[i][j]] = INF;
				if (!t[i][j])
					continue;
				for (int k = 0; k < n; k++) {
					if (k == i)
						continue;
					int index1 = k*100+t[i][j];
					int index2 = i*100+t[i][j];
					if (adjList.count(index1))
						adjList[index1][index2] = adjList[index2][index1] = 60;
				}
			}
		}
		// for (auto it: adjList) {
		// 	for (auto ths: it.second) {
		// 		printf("%d %d = %d\n", it.first, ths.first, ths.second);
		// 	}
		// }
		dijkstra();
		// for (auto it: dist) {
		// 	printf("%d %d\n", it.first, it.second);
		// }
		int smallest = INF;
		for (int i = 0; i < n; i++) {
			if (dist.count(i*100+k))
				smallest = min(smallest, dist[i*100+k]);
		}
		if (smallest == INF)
			printf("IMPOSSIBLE\n");
		else
			printf("%d\n", smallest);
		// for (int i = 0; i < n; i++) {
		// 	for (int j: t[i])
		// 		printf("%d ", j);
		// 	printf("\n");
		// }
	}
	return 0;
}