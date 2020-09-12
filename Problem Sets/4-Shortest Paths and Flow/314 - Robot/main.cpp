#include <cstdio>
#include <vector>
#include <queue>
using namespace std;

struct POINT {
    int i, j, dir, dis;
    POINT(int _i, int _j, int _dir, int _dis): i(_i), j(_j), dir(_dir), dis(_dis) {}
};

vector<vector<vector<int>>> v;
int b1, b2, e1, e2, face;
int m, n;
queue<POINT> q;
const int dirr[] = {-1, 0, 1, 0};
const int dirc[] = {0, 1, 0, -1};

bool valid(int i, int j) {
	if (i < 0 || i > m || j < 0 || j > n)
		return false;
	if (v[i][j][0] == 1)
		return false;
	return true;
}

int bfs() {
	while (!q.empty())
		q.pop();
	q.push(POINT(b1, b2, face, 0));
	while (!q.empty()) {
		POINT cur = q.front();
		q.pop();
		int i = cur.i, j = cur.j, dir = cur.dir, dis = cur.dis;
		if (!valid(i, j))
			break;
		if (v[i][j][0] == 3)
			return dis;
		if (v[i][j][dir] == 4)
			continue;
		v[i][j][dir] = 4;
		q.push(POINT(i, j, (dir+1)%4, dis+1));
		q.push(POINT(i, j, (dir+3)%4, dis+1));
		if (valid(i+dirr[dir], j+dirc[dir])) {
			q.push(POINT(i+dirr[dir], j+dirc[dir], dir, dis+1));
			if (valid(i+2*dirr[dir], j+2*dirc[dir])) {
				q.push(POINT(i+2*dirr[dir], j+2*dirc[dir], dir, dis+1));
				if (valid(i+3*dirr[dir], j+3*dirc[dir]))
					q.push(POINT(i+3*dirr[dir], j+3*dirc[dir], dir, dis+1));
			}
		}
	}
	return -1;
}

int main() {
	while (scanf("%d %d", &m, &n), m) {
		vector<int> unit(4, 0);
		v.assign(m+1, vector<vector<int>>());
		for (int i = 0; i < m+1; i++)
			v[i].assign(n+1, unit);
		for (int i = 1; i < m+1; i++)
			for (int j = 1; j < n+1; j++)
				scanf("%d", &v[i][j][0]);
		char tmp[6];
		scanf("%d %d %d %d %s", &b1, &b2, &e1, &e2, tmp);
		if (tmp[0] == 'n')
			face = 0;
		else if (tmp[0] == 'e')
			face = 1;
		else if (tmp[0] == 's')
			face = 2;
		else
			face = 3;
		if (v[b1][b2][0] == 1 || v[e1][e2][0] == 1) {
			printf("-1\n");
			continue;
		}
		for (int k = 0; k < 4; k++) {
			v[b1][b2][k] = 2;
			v[e1][e2][k] = 3;
		}
		for (int i = 1; i < m+1; i++) {
			for (int j = 1; j < n+1; j++) {
				if (v[i][j][0] == 1) {
					for (int k = 0; k < 4; k++) {
						v[i][j][k] = 1;
						v[i-1][j-1][k] = 1;
						v[i][j-1][k] = 1;
						v[i-1][j][k] = 1;
					}
				}
			}
		}
		for (int i = 0; i < m+1; i++) {
			for (int k = 0; k < 4; k++) {
				v[i][0][k] = 1;
				v[i][n][k]	= 1;
			}
		}
		for (int i = 0; i < n+1; i++) {
			for (int k = 0; k < 4; k++) {
				v[0][i][k] = 1;
				v[m][i][k]	= 1;
			}
		}
		printf("%d\n", bfs());
	}
	return 0;
}