#include <cstdio>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

#define INF 0x3f3f3f3f
typedef vector<int> vi;
const int MX = 100+5;

int n, s, t;
int res[MX][MX];
int f, mf;
vi p;

void augment(int v, int minEdge) {
	if (v == s) {
		f = minEdge;
		return;
	} else if (p[v] != -1) {
		augment(p[v], min(minEdge, res[p[v]][v]));
		res[p[v]][v] -= f;
		res[v][p[v]] -= f;
	}
}

int main() {
	int index = 1;
	while (scanf("%d", &n), n) {
		printf("Network %d\n", index++);
		int c;
		scanf("%d %d %d", &s, &t, &c);
		s--;
		t--;
		memset(res, 0, sizeof res);
		int a, b, w;
		for (int i = 0; i < c; i++) {
			scanf("%d %d %d", &a, &b, &w);
			a--;
			b--;
			res[a][b] += w;
			res[b][a] += w;
		}
		mf = 0;
		while (1) {
			f = 0;
			vi dist(n, INF);
			dist[s] = 0;
			queue<int> q;
			q.push(s);
			p.assign(n, -1);
			while (!q.empty()) {
				int u = q.front();
				q.pop();
				if (u == t)
					break;
				for (int v = 0; v < n; v++) {
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
		printf("The bandwidth is %d.\n\n", mf);
	}
	return 0;
}