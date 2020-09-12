#include <cstdio>
using namespace std;

const int MX = 100+7;
const int MXS = 5*1e4+7;
char stage[MX][MX];
char instr[MXS];
int N, M, S;
int orient; // 0 N North, 1 L East, 2 S South, 3 O West
// D right 90, E left 90, F forward
int collect;

void dfs(int r, int c, int ins) {
	if (ins == S)
		return;
	if (instr[ins] == 'D') {
		orient = (orient+1) % 4;
		dfs(r, c, ins+1);
	} else if (instr[ins] == 'E') {
		orient = (orient+3) % 4;
		dfs(r, c, ins+1);
	} else {
		int nextr = r, nextc = c;
		if (orient == 0)
			nextr -= 1;
		else if (orient == 1)
			nextc += 1;
		else if (orient == 2)
			nextr += 1;
		else
			nextc -= 1;
		if (nextr < 0 || nextr >= N || nextc < 0 || nextc >= M ||
			stage[nextr][nextc] == '#')
			dfs(r, c, ins+1);
		else {
			if (stage[nextr][nextc] == '*') {
				stage[nextr][nextc] = '.';
				collect++;
			}
			dfs(nextr, nextc, ins+1);
		}
	}
}

int main() {
	while (scanf("%d %d %d", &N, &M, &S), N) {
		for (int i = 0; i < N; i++)
			scanf("%s", stage[i]);
		scanf("%s", instr);
		int r, c;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (stage[i][j] == 'N') {
					orient = 0;
					r = i, c = j;
					goto finish;
				} else if (stage[i][j] == 'L') {
					orient = 1;
					r = i, c = j;
					goto finish;
				} else if (stage[i][j] == 'S') {
					orient = 2;
					r = i, c = j;
					goto finish;
				} else if (stage[i][j] == 'O') {
					orient = 3;
					r = i, c = j;
					goto finish;
				}
			}
		}
		finish:
		collect = 0;
		dfs(r, c, 0);
		printf("%d\n", collect);
	}
	return 0;
}