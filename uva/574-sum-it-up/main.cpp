#include <bits/stdc++.h>

using namespace std;

int cnt;

void DFS(int* d, vector<int>& v,
	int index, int acc, int t, int n) {
	if (acc == t) {
		cnt++;
		for (int i = 0; i < v.size(); i++) {
			if (i)
				printf("+");
			printf("%d", v[i]);
		}
		printf("\n");
		return;
	}
	if (index>=n || acc>t)
		return;
	for (int i = index; i < n; i++) {
		if (i>index && d[i]==d[i-1])
			continue;
		v.push_back(d[i]);
		acc += d[i];
		DFS(d, v, i+1, acc, t, n);
		acc -= d[i];
		v.pop_back();
	}
}

int main() {
	int t, n;
	while (scanf("%d %d", &t, &n), t) {
		printf("Sums of %d:\n", t);
		int d[n];
		for (int i = 0; i < n; i++)
			scanf("%d", &d[i]);
		vector<int> v;
		cnt = 0;
		DFS(d, v, 0, 0, t, n);
		if (!cnt)
			printf("NONE\n");
	}
	return 0;
}