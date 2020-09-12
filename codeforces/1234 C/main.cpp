#include <bits/stdc++.h>
using namespace std;

bool success;
const int MX = 2*1e5+7;
char pipe[2][MX];

void dfs(int row, int col, int n, bool fromLeft) {
	if (row == 1 && col == n)
		return;
	if (col >= n) {
		success = false;
		return;
	}
	if (pipe[row][col] == '1' || pipe[row][col] == '2') {
		if (fromLeft)
			dfs(row, col+1, n, fromLeft);
		else
			success = false;
	} else {
		if (fromLeft)
			dfs(1-row, col, n, !fromLeft);
		else
			dfs(row, col+1, n, !fromLeft);
	}
}

int main() {
	int test;
	scanf("%d", &test);
	while (test--) {
		int n;
		scanf("%d", &n);
		scanf("%s %s", pipe[0], pipe[1]);
		success = true;
		dfs(0, 0, n, true);
		if (success)
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}