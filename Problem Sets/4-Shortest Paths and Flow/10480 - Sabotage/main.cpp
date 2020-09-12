#include <cstdio>
#include <vector>
#include <queue>
#include <cstring>
#include <unordered_set>
using namespace std;

#define INF 0x3f3f3f3f
typedef vector<int> vi;
const int MX = 50+5;

int n, m;
int s = 1, t = 2;
int res[MX][MX];
int f, mf;
vector<vi> adjList;
vi p;
vector<vi> minCut;
unordered_set<int> S_component;

void augment(int v, int minEdge) {
	if (v == s) {
		f = minEdge;
		return;
	} else if (p[v] != -1) {
		augment(p[v], min(minEdge, res[p[v]][v]));
		res[p[v]][v] -= f;
		res[v][p[v]] += f;
	}
}

void bfs() {
	queue<int> q;
	q.push(s);
	S_component.clear();
	while (!q.empty()) {
		int front = q.front();
		q.pop();
		S_component.insert(front);
		for (int i: adjList[front]) {
			if (S_component.count(i))
				continue;
			if (res[front][i])
				q.push(i);
		}
	}
}

void cut() {
	minCut.clear();
	for (int i: S_component) {
		for (int j: adjList[i]) {
			if (!S_component.count(j))
				minCut.push_back({i, j});
		}
	}
}

int main() {
	int test = 0;
	while (scanf("%d %d", &n, &m), n) {
		if (test++)
			printf("\n");
		memset(res, 0, sizeof(res));
		int a, b, w;
		adjList.assign(n+1, vi());
		for (int i = 0; i < m; i++) {
			scanf("%d %d %d", &a, &b, &w);
			res[a][b] += w;
			res[b][a] += w;
			adjList[a].push_back(b);
			adjList[b].push_back(a);
		}
		mf = 0;
		while (1) {
			f = 0;
			vi dist(n+1, INF);
			dist[s] = 0;
			queue<int> q;
			q.push(s);
			p.assign(n+1, -1);
			while (!q.empty()) {
				int u = q.front();
				q.pop();
				if (u == t)
					break;
				for (int v = 1; v <= n; v++) {
					if (res[u][v] > 0 && dist[v] == INF) {
						dist[v] = dist[u] + 1;
						q.push(v);
						p[v] = u;
					}
				}
			}
			augment(t, INF);
			if (f == 0)
				break;
			mf += f;
		}
		// for (int i = 1; i <= n; i++) {
		// 	for (int j = i+1; j <= n; j++) {
		// 		printf("%d to %d = %d\n", i, j, res[i][j]);
		// 	}
		// }
		bfs();
		cut();
		for (vi i: minCut)
			printf("%d %d\n", i[0], i[1]);
	}
	return 0;
}