#include <bits/stdc++.h>
using namespace std;

const int inf = INT_MAX, N = 107, M = 4007;
int head[N], ver[M], edge[M], Next[M];
int v[N], incf[N], pre[N];
int s, t, tot, maxflow;

void add(int x, int y, int z) {
	ver[++tot] = y, edge[tot] = z, Next[tot] = head[x], head[x] = tot;
	ver[++tot] = x, edge[tot] = 0, Next[tot] = head[y], head[y] = tot;
}

void addun(int x, int y, int z) {
	ver[++tot] = y, edge[tot] = z, Next[tot] = head[x], head[x] = tot;
	ver[++tot] = x, edge[tot] = z, Next[tot] = head[y], head[y] = tot;
}

bool bfs() {
	memset(v, 0, sizeof(v));
	queue<int> q;
	q.push(s);
	v[s] = 1;
	incf[s] = inf;
	while (q.size()) {
		int x = q.front();
		q.pop();
		for (int i = head[x]; i; i = Next[i]) {
			if (edge[i]) {
				int y = ver[i];
				if (v[y])
					continue;
				incf[y] = min(incf[x], edge[i]);
				pre[y] = i;
				q.push(y);
				v[y] = 1;
				if (y == t)
					return true;
			}
		}
	}
	return false;
}

void update() {
	int x = t;
	while (x != s) {
		int i = pre[x];
		edge[i] -= incf[t];
		edge[i^1] += incf[t];
		x = ver[i^1];
	}
	maxflow += incf[t];
}

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(0);
    int m, w;
    while (cin >> m >> w, m) {
    	int a[m], b[w];
    	int id, c;
    	s = 1;
    	t = m;
    	tot = 1;
    	maxflow = 0;
    	memset(head, 0, sizeof(head));
    	for (int i = 0; i < m-2; i++) {
    		cin >> id >> c;
    		add(id, id+m, c);
    	}
    	int u, v, d;
    	for (int i = 0; i < w; i++) {
    		cin >> u >> v >> d;
    		if (u == 1 && v == m)
    			addun(u, v, d);
    		else if (u == 1) {
    			add(u, v, d);
    			add(v, u+m, d);
    		} else if (v == m) {
    			add(u+m, v, d);
    			add(v, u, d);
    		} else {
    			add(u+m, v, d);
    			add(v+m, u, d);
    		}
    	}
    	while (bfs())
    		update();
    	cout << maxflow << '\n';
    }
	return 0;
}