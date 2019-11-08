#include <cstdio>
#include <vector>
#include <queue>
#include <cstring>
#include <unordered_set>
#include <set>
using namespace std;

#define INF 0x3f3f3f3f
typedef vector<int> vi;
const int MX = 50*2+5;

int M, W;
int s, t;
int res[MX][MX];
int origin[MX][MX];
int f, mf;
vector<vi> adjList;
vi p;
vector<vi> minCut;
unordered_set<int> S_component;
int cost;
int total;

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
			if (!S_component.count(j)) {
				minCut.push_back({i, j});
				cost += origin[i][j];
			}
		}
	}
}

void maxFLow() {
	memcpy(res, origin, sizeof(res));
	mf = 0;
	while (1) {
		f = 0;
		vi dist(total+1, INF);
		dist[s] = 0;
		queue<int> q;
		q.push(s);
		p.assign(total+1, -1);
		while (!q.empty()) {
			int u = q.front();
			q.pop();
			if (u == t)
				break;
			for (int v = 1; v <= total; v++) {
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
	bfs();
	cost = 0;
	cut();
}

int main() {
	while (scanf("%d %d", &M, &W), M) {
		memset(res, 0, sizeof(res));
		int out = M-1;
		total = 2*M-2;
		s = 1, t = M;
		adjList.assign(total+1, vi());
		int a, b, w;
		for (int i = 0; i < M-2; i++) {
			scanf("%d %d", &a, &w);
			int a_out = a + out;
			res[a][a_out] += w;
			adjList[a].push_back(a_out);
		}
		for (int i = 0; i < W; i++) {
			scanf("%d %d %d", &a, &b, &w);
			int a_out = a, b_out = b;
			if (a != s && a != t)
				a_out = a + out;
			if (b != s && b != t)
				b_out = b + out;
			res[a_out][b] += w;
			res[b_out][a] += w;
			adjList[a_out].push_back(b);
			adjList[b_out].push_back(a);
		}
		memcpy(origin, res, sizeof(res));

		maxFLow();
		int record = cost;
		swap(s, t);
		maxFLow();
		record = min(cost, record);
		printf("%d\n", record);
	}
	return 0;
}