#include <bits/stdc++.h>
using namespace std;

const int MX = 1000;
int d[MX+1];
int num[201];

int solve(int N, int M, int D) {
	printf("%d %d %d\n", N, M, D);
	int ret = 0;
	memset(d, -1, sizeof(d));
	d[0] = 0;
	for (int i = 1; i <= N; i++) {
		for (int j = 0; j <= MX; j++) {
			if (d[j] != -1) {
				int cur = j+num[i];
				if (cur <= MX) {
					if (d[cur] == -1)
						d[cur] = 0;
					d[cur] += d[j] + 1;
					if (d[cur] >= M && j % D == 0) {
						ret += d[cur] / M;
						d[cur] %= M;
					}
				}
			}
		}
	}
	return ret;
}

int main() {
	int N, Q, M, D;
	int index = 1;
	while (scanf("%d %d", &N, &Q), N) {
		printf("SET %d:\n", index++);
		for (int i = 1; i <= N; i++)
			scanf("%d", &num[i]);
		for (int i = 1; i <= Q; i++) {
			scanf("%d %d", &M, &D);
			printf("QUERY %d: %d\n", i, solve(N, M, D));
		}
		
		
	}
	return 0;
}