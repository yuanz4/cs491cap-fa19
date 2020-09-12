#include <cstdio>
#include <cstring>

const int MX = 200+5; 
int n, q, num[MX], rec[MX];
long long dp[15][MX * MX];
 
void solve(int cas) {
	int D, N, sum = 0;
	long long ans = 0;
	scanf("%d %d", &D, &N);
	for (int i = 0; i < n; i++) {
		rec[i] = (num[i] % D + D) % D;
		sum += rec[i];
	}
	memset(dp, 0, sizeof dp);
	dp[0][0] = 1;
	for (int i = 0; i < n; i++) {
		for (int j = N - 1; j >= 0; j--) {
			for (int k = 0; k <= sum; k++) {
				dp[j + 1][k + rec[i]] += dp[j][k];
			}
		}
		// for (int j = 0; j <= N; j++) {
		// 	for (int k = 0; k <= sum; k++) {
		// 		printf("%lld ", dp[j][k]);
		// 	}
		// 	printf("\n");
		// }
		// printf("------------------------------\n");
	}
	for (int i = 0; i <= sum; i += D)
		ans += dp[N][i];
	printf("QUERY %d: %lld\n", cas, ans);
}
 
int main () {
	int cas = 1;
	while (scanf("%d%d", &n, &q), n + q) {
		for (int i = 0; i < n; i++)
		scanf("%d", &num[i]);
		printf("SET %d:\n", cas++);
		for (int i = 1; i <= q; i++)
			solve(i);
	}
	return 0;
}