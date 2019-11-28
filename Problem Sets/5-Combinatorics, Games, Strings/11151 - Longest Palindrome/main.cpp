#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int MX = 1000+7;

int main() {
	int test;
	scanf("%d", &test);
	char tmp[MX], s[MX];
	fgets(tmp, MX, stdin);
	while (test--) {
		fgets(tmp, MX, stdin);
		if (tmp[0] == '\r' || tmp[0] == '\n') {
			printf("0\n");
			continue;
		}
		sscanf(tmp, "%s", s);
		int n = strlen(s);
		int d[n][n];
		memset(d, 0, sizeof(d));
		for (int i = 0; i < n; i++)
			d[i][i] = 1;
		for (int i = 0; i < n-1; i++)
			d[i][i+1] = s[i] == s[i+1] ? 2 : 1;
		for (int len = 2; len < n; len++) {
			for (int l = 0; l + len < n; l++) {
				int r = l + len;
				if (s[l] == s[r])
					d[l][r] = d[l+1][r-1] + 2;
				else
					d[l][r] = max(d[l+1][r], d[l][r-1]);
			}
		}
		printf("%d\n", d[0][n-1]);
	}
	return 0;
}