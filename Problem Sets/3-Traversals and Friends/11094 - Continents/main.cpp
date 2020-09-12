#include <bits/stdc++.h>
using namespace std;

int dr[] = {1,-1,0,0};
int dc[] = {0,0,1,-1};
int m, n;
int myr, myc;
char** grid;
bool mine;

int floodfill(int r, int c, char land) {
	if (r < 0 || r >= m)
		return 0;
	c = (c + n) % n;
	if (grid[r][c] != land)
		return 0;
	int ans = 1;
	if (r == myr && c == myc)
		mine = true;
	grid[r][c] = land+1;
	for (int d = 0; d < 4; d++)
		ans += floodfill(r + dr[d], c + dc[d], land);
	return ans;
}

int main() {
	while (~scanf("%d %d", &m, &n)) {
		grid = new char*[m];
		for (int i = 0; i < m; i++) {
			grid[i] = new char[n];
			for (int j = 0; j < n; j++)
				scanf(" %c", &grid[i][j]);
		}
		scanf("%d %d", &myr, &myc);
		char land = grid[myr][myc];
		mine = false;
		int ret = 0;
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				int cur = floodfill(i, j, land);
				if (mine)
					mine = false;
				else
					ret = max(ret, cur);
			}
		}
		printf("%d\n", ret);
	}
	return 0;
}