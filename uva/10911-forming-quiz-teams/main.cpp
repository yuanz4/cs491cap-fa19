#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;

const int MX = 16;
double dist[MX][MX], memo[1<<MX];
int N, target;

double matching(int bit) {
	if (bit == target)
		return memo[bit] = 0;
	if (memo[bit] >= 0)
		return memo[bit];
	int p1, p2;
	double ans = 1e8;
	for (p1 = 0; p1 < 2 * N; p1++)
		if (!(bit & (1 << p1)))
			break;
	for (p2 = p1 + 1; p2 < 2 * N; p2++)
		if (!(bit & (1 << p2)))
			ans = min(ans, dist[p1][p2] + matching(bit | (1 << p1) | (1 << p2)));
	return memo[bit] = ans;
}

int main() {
	char name[25];
	int Case = 1;
	while (scanf("%d", &N), N) {
		double x[MX], y[MX];
		for (int i = 0; i < 2 * N; i++)
			scanf("%s %lf %lf", name, &x[i], &y[i]);
		for (int i = 0; i < 2 * N; i++) {
			for (int j = i; j < 2 * N; j++) {
				dist[i][j] = dist[j][i] = hypot(x[i]-x[j], y[i]-y[j]);
			}
		}
		memset(memo, -1, sizeof(memo));
		target = (1 << (2 * N)) - 1;
		printf("Case %d: %.2lf\n", Case++, matching(0));
	}
	return 0;
}