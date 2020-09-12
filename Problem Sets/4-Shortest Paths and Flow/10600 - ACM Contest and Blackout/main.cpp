#include <cstdio>
#include <vector>
#include <unordered_map>
#include <cmath>
#include <algorithm>
using namespace std;

typedef pair<int, int> ii;
const int MX = 100+7;
const int INF = 0x3f3f3f3f;

int p[MX];
vector<pair<int, ii>> edgeList;
int N, M;

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

int Kruscal(int edge, vector<int>& v) {
	for (int i = 1; i <= N; i++)
		p[i] = i;
	int mstCost = 0;
	for (int i = 0; i < M; i++) {
		pair<float, ii> cur = edgeList[i];
		if (cur.first == -1)
			continue;
		if (!same(cur.second.first, cur.second.second)) {
			join(cur.second.first, cur.second.second);
			mstCost += cur.first;
			edge--;
			v.push_back(i);
		}
	}
	if (edge != 0)
		return INF;
	return mstCost;
}

int main() {
	int test;
	scanf("%d", &test);
	while (test--) {
		scanf("%d %d", &N, &M);
		int u, v, w;
		edgeList.clear();
		for (int i = 0; i < M; i++) {
			scanf("%d %d %d", &u, &v, &w);
			edgeList.push_back(make_pair(w, ii(u, v)));
		}
		sort(edgeList.begin(), edgeList.end());
		int edge = N - 1;
		vector<int> mstEdge;
		int minFirst = Kruscal(edge, mstEdge);
		int minSecond = INF;
		vector<int> unused;
		for (int i: mstEdge) {
			int w = edgeList[i].first;
			edgeList[i].first = -1;
			int result = Kruscal(edge, unused);
			minSecond = min(minSecond, result);
			edgeList[i].first = w;
		}
		printf("%d %d\n", minFirst, minSecond);
	}
	return 0;
}