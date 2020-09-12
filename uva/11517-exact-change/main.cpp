#include <bits/stdc++.h>

using namespace std;

const int MX = 10000*2+7;

int main() {
	int test;
	scanf("%d", &test);
	int money, n;
	while (test--) {
		scanf("%d %d", &money, &n);
		int coin[n+1];
		for (int i = 1; i <= n; i++)
			scanf("%d", &coin[i]);
		int d[n+1][MX+1];
		memset(d, -1, sizeof(d));
		for (int i = 0; i <= n; i++)
			d[i][0] = 0;
		for (int i = 1; i <= n; i++) {
			for (int j = 0; j <= MX; j++) {
				if (d[i-1][j] != -1) {
					if (j+coin[i] <= MX) {
						int change;
						if (d[i][j+coin[i]] == -1)
							change = d[i-1][j]+1;
						else
							change = min(d[i][j+coin[i]], d[i-1][j]+1);
						for (int k = i; k <= n; k++) {
							d[k][j+coin[i]] = change;
						}
					}
				}
			}
		}
		for (int i = money; i <= MX; i++) {
			if (d[n][i] != -1) {
				printf("%d %d\n", i, d[n][i]);
				break;
			}
		}
	}
	return 0;
}