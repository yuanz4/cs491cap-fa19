#include <bits/stdc++.h>
using namespace std;

int di[] = {0, -1, 0, 1};
int dj[] = {-1, 0, 1, 0};

void dfs(char** d, int i, int j, int n) {
	if (i < 0 || i >= n || j < 0 || j >= n)
		return;
	if (d[i][j] != '.') {
		d[i][j] = '.';
		for (int it = 0; it < 4; it++)
			dfs(d, i+di[it], j+dj[it], n);
	}
}

int main() {
	int T;
	scanf("%d", &T);
	int index = 1;
	while (T--) {
		int n;
		scanf("%d", &n);
		char** d = new char*[n];
		for (int i = 0; i < n; i++)
			d[i] = new char[n];
		char tmp[107];
		for (int i = 0; i < n; i++) {
			scanf("%s", tmp);
			for (int j = 0; j < n; j++)
				d[i][j] = tmp[j];
		}
		int ret = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (d[i][j] == 'x') {
					ret++;
					dfs(d, i, j, n);
				}
			}
		}
		printf("Case %d: %d\n", index++, ret);
	}
	return 0;
}