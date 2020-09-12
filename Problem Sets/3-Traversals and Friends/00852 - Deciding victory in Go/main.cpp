#include <cstdio>
using namespace std;

char board[9][10];
int state; // 0 clear, 1 white, 2 black, -1 none

void dfs(int i, int j) {
	if (i < 0 || i >= 9 || j < 0 || j >= 9)
		return;
	if (board[i][j] == '?')
		return;
	if (board[i][j] == 'O') {
		if (state == 0)
			state = 1;
		else if (state == 2)
			state = -1;
	} else if (board[i][j] == 'X') {
		if (state == 0)
			state = 2;
		else if (state == 1)
			state = -1;
	} else if (board[i][j] == '.') {
		board[i][j] = '?';
		dfs(i-1, j);
		dfs(i+1, j);
		dfs(i, j-1);
		dfs(i, j+1);
	}
}

void reset() {
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			if (board[i][j] == '?') {
				if (state == -1)
					board[i][j] = '*';
				else if (state == 1)
					board[i][j] = 'O';
				else if (state == 2)
					board[i][j] = 'X';
			}
		}
	}
}

int main() {
	int test;
	scanf("%d", &test);
	while (test--) {
		for (int i = 0; i < 9; i++)
			scanf("%s", board[i]);
		int white = 0, black = 0;
		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 9; j++) {
				if (board[i][j] == '.') {
					state = 0;
					dfs(i, j);
					reset();
				}
				if (board[i][j] == 'O')
					white++;
				if (board[i][j] == 'X')
					black++;
			}
		}
		// for (int i = 0; i < 9; i++)
		// 	printf("%s\n", board[i]);
		printf("Black %d White %d\n", black, white);
	}
	return 0;
}