#include <cstdio>
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

const int MX = 200+7;
const int dr[] = {0, 0, 1, -1};
const int dc[] = {1, -1, 0, 0};
const char* hieroglyph = "WAKJSD";
char grid[MX][MX];
char tmp[MX];
int H, W, w;
int blank;

void print() {
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++) {
			printf("%c", grid[i][j]);
		}
		printf("\n");
	}
}

void fill(int r, int c, char ch, char to) {
	if (r < 0 || r >= H || c < 0 || c >= W)
		return;
	if (grid[r][c] != ch)
		return;
	grid[r][c] = to;
	for (int i = 0; i < 4; i++)
		fill(r+dr[i], c+dc[i], ch, to);
}

void background() {
	for (int i = 0; i < W; i++) {
		fill(0, i, '0', '+');
		fill(H-1, i, '0', '+');
	}
	for (int i = 0; i < H; i++) {
		fill(i, 0, '0', '+');
		fill(i, W-1, '0', '+');
	}
}

// + background, 1 origin black, ? changed black, 0 origin white, * changed white
void dfs(int r, int c) {
	if (r < 0 || r >= H || c < 0 || c >= W)
		return;
	if (grid[r][c] == '+' || grid[r][c] == '?' || grid[r][c] == '*')
		return;
	if (grid[r][c] == '1') {
		grid[r][c] = '?';
		for (int i = 0; i < 4; i++)
			dfs(r+dr[i], c+dc[i]);
	} else {
		blank++;
		fill(r, c, '0', '*');
	}
}

int main() {
	int index = 1;
	while (scanf("%d %d", &H, &w), H) {
		W = w * 4;
		for (int i = 0; i < H; i++) {
			scanf("%s", tmp);
			for (int j = 0; j < w; j++) {
				int word;
				char cur = tmp[j];
				if (cur >= '0' && cur <= '9')
					word = cur-'0';
				else
					word = (cur-'a')+10;
				for (int k = 0; k < 4; k++) {
					grid[i][j*4+k] = ((word>>(3-k))&1) + '0';
				}
			}
		}
		background();
		string ret;
		for (int i = 0; i < H; i++) {
			for (int j = 0; j < W; j++) {
				if (grid[i][j] == '1') {
					blank = 0;
					dfs(i, j);
					ret += hieroglyph[blank];
				}
			}
		}
		sort(ret.begin(), ret.end());
		// print();
		printf("Case %d: ", index++);
		cout << ret << endl;
	}
	return 0;
}