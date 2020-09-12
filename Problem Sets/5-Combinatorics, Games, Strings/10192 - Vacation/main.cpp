#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

const int MX = 100+7;

int main() {
	int test = 1;
	char a[MX], b[MX];
	while (true) {
		// scanf(" %[^\r\n]", a);
		gets(a);
		if (a[0] == '#')
			break;
		// scanf(" %[^\r\n]", b);
		gets(b);
		int n = strlen(a);
		int m = strlen(b);
		int d[MX][MX] = {0};
		for (int i = 1; i < n+1; i++) {
			for (int j = 1; j < m+1; j++) {
				if (a[i-1] == b[j-1])
					d[i][j] = d[i-1][j-1] + 1;
				else
					d[i][j] = max(d[i-1][j], d[i][j-1]);
			}
		}
		printf("Case #%d: you can visit at most %d cities.\n", test++, d[n][m]);
	}
	return 0;
}