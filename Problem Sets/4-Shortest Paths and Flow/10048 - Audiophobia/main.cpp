#include <cstdio>
#include <vector>
#include <unordered_map>
#include <cmath>
#include <algorithm>
#include <queue>
#include <unordered_set>
using namespace std;

typedef vector<int> vi;
typedef pair<int, int> ii;
const int MX = 100+7;
const int INF = 0x3f3f3f3f;

int p[MX];
vector<pair<int, ii>> edgeList;
unordered_map<int, unordered_map<int, int>> mstEdge;
int C, S, Q;

int find(int a) {
	if (a != p[a])
		return p[a] = find(p[a]);
	return a;
}

bool same(int a, int b) {
	if (find(a) == find(b))
		return true;
	return false;
}

void join(int a, int b) {
	p[find(a)] = find(b);
}

void Kruscal() {
	mstEdge.clear();
	sort(edgeList.begin(), edgeList.end());
	for (int i = 1; i <= C; i++)
		p[i] = i;
	for (int i = 0; i < S; i++) {
		pair<float, ii> cur = edgeList[i];
		int u = cur.second.first, v = cur.second.second;
		int w = cur.first;
		if (!same(u, v)) {
			join(u, v);
			mstEdge[u][v] = w;
			mstEdge[v][u] = w;
		}
	}
}

int bfs(int start, int end) {
	queue<vi> q;
	q.push({start, 0, 0});
	unordered_set<int> visited;
	while (!q.empty()) {
		vi front = q.front();
		q.pop();
		int next = front[0], w = front[1], len = front[2];
		visited.insert(next);
		len = max(len, w);
		if (next == end)
			return len;
		for (ii i: mstEdge[next]) {
			if (!visited.count(i.first)) {
				q.push({i.first, i.second, len});
			}
		}
	}
	return -1;
}

int main() {
	int test = 1;
	while (scanf("%d %d %d", &C, &S, &Q), C) {
		if (test != 1)
			printf("\n");
		printf("Case #%d\n", test++);
		int u, v, w;
		edgeList.clear();
		for (int i = 0; i < S; i++) {
			scanf("%d %d %d", &u, &v, &w);
			edgeList.push_back(make_pair(w, ii(u, v)));
		}
		Kruscal();
		int start, end;
		for (int i = 0; i < Q; i++) {
			scanf("%d %d", &start, &end);
			int dist = bfs(start, end);
			if (dist == -1)
				printf("no path\n");
			else
				printf("%d\n", dist);
		}
	}
	return 0;
}