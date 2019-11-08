#include <cstdio>
#include <cstring>
using namespace std;

const int MX = 100+7;
const int dr[] = {1, -1, 1, -1};
const int dc[] = {-1, 1, 1, -1};
int R, C, M, N;
int grid[MX][MX];
int even, odd;

bool valid(int r, int c) {
	if (r < 0 || r >= R || c < 0 || c >= C)
		return false;
	if (grid[r][c] == -1)
		return false;
	return true;
}

void measure(int r, int c) {
	int total = 0;
	if (M == 0 || N == 0) {
		for (int i = 0; i < 2; i++) {
			if (valid(r+dr[i]*M, c+dc[i]*N))
				total++;
			if (valid(r+dr[i]*N, c+dc[i]*M))
				total++;
		}
	} else {
		for (int i = 0; i < 4; i++) {
			if (valid(r+dr[i]*M, c+dc[i]*N))
				total++;
			if (M != N) {
				if (valid(r+dr[i]*N, c+dc[i]*M))
					total++;
			}
		}
	}
	if (total%2 == 0) {
		grid[r][c] = 2;
		even++;
	} else {
		grid[r][c] = 1;
		odd++;
	}
}

void dfs(int r, int c) {
	if (!valid(r, c))
		return;
	if (grid[r][c] != 0)
		return;
	measure(r, c);
	for (int i = 0; i < 4; i++) {
		dfs(r+dr[i]*M, c+dc[i]*N);
		dfs(r+dr[i]*N, c+dc[i]*M);
	}
}

int main() {
	int test;
	scanf("%d", &test);
	for (int t = 1; t <= test; t++) {
		scanf("%d %d %d %d", &R, &C, &M, &N);
		int water;
		scanf("%d", &water);
		int a, b;
		memset(grid, 0, sizeof grid);
		while (water--) {
			scanf("%d %d", &a, &b);
			grid[a][b] = -1;
		}
		even = 0, odd = 0;
		dfs(0, 0);
		printf("Case %d: %d %d\n", t, even, odd);
	}
	return 0;
}