#include <cstdio>
#include <vector>
#include <unordered_map>
#include <cmath>
#include <algorithm>
using namespace std;

typedef pair<int, int> ii;
const int MX = 500+7;
int p[MX];

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

int main() {
	int test, S, P;
	scanf("%d", &test);
	while (test--) {
		scanf("%d %d", &S, &P);
		int x, y;
		int count = 0;
		unordered_map<int, ii> m;
		for (int i = 0; i < P; i++) {
			scanf("%d %d", &x, &y);
			m[count++] = make_pair(x, y);
		}
		for (int i = 0; i < count; i++)
			p[i] = i;
		vector<pair<float, ii>> edgeList;
		for (int i = 0; i < count; i++) {
			for (int j = i+1; j < count; j++) {
				float x_diff = m[i].first - m[j].first;
				float y_diff = m[i].second - m[j].second;
				float w = sqrt(pow(x_diff, 2) + pow(y_diff, 2));
				edgeList.push_back(make_pair(w, ii(i, j)));
			}
		}
		sort(edgeList.begin(), edgeList.end());
		int edge = P - S;
		float last;
		for (int i = 0; i < edgeList.size(); i++) {
			pair<float, ii> front = edgeList[i];
			if (!same(front.second.first, front.second.second)) {
				join(front.second.first, front.second.second);
				last = front.first;
				edge--;
				if (!edge)
					break;
			}
		}
		printf("%.2f\n", last);
	}
	return 0;
}