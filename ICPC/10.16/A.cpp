#include <cstdio>
using namespace std;

const int MX = 1000000+7;

int main() {
	int n, N;
	scanf("%d %d", &n, &N);
	int num[n];
	for (int i = 0; i < n; i++)
		scanf("%d", &num[i]);
	int dp[N+1][MX];
	dp[0][0] = 1;
	for (int i = 0; i < n; i++) {
		for (int j = N - 1; j >= 0; j--) {
			for (int k = 0; k < MX; k++) {
				dp[j + 1][k + num[i]] += dp[j][k];
			}
		}
	}
	int index = 0;
	for (int i = 0; i < MX; i++) {
		if (index)
			printf(" ");
		index++;
		if (dp[i])
			printf("%d", i);
	}
	printf("\n");
	return 0;
}