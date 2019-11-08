#include <cstdio>
#include <cstring>
#include <queue>
#include <vector>
using namespace std;

typedef vector<int> vi;
const int MX = 30+7;
const int INF = 0x3f3f3f3f;
const int dl[] = {0, 0, 1, -1, 0, 0};
const int dr[] = {0, 0, 0, 0, 1, -1};
const int dc[] = {1, -1, 0, 0, 0, 0};

int main() {
	int l, r, c;
	char d[MX][MX][MX];
	int dist[MX][MX][MX];
	while (scanf("%d %d %d", &l, &r, &c), l) {
		memset(d, 0, sizeof d);
		memset(dist, 0x3f, sizeof dist);
		for (int i = 0; i < l; i++) {
			for (int j = 0; j < r; j++) {
				scanf("%s", d[i][j]);
			}
		}
		queue<vi> q;
		for (int i = 0; i < l; i++) {
			for (int j = 0; j < r; j++) {
				for (int k = 0; k < c; k++) {
					if (d[i][j][k] == 'S') {
						q.push({i, j, k});
						dist[i][j][k] = 0;
						break;
					}
				}
			}
		}
		bool found = false;
		int i, j, k;
		while (!q.empty()) {
			vi cur = q.front();
			q.pop();
			i = cur[0], j = cur[1], k = cur[2];
			if (d[i][j][k] == 'E') {
				found = true;
				break;
			}
			for (int dir = 0; dir < 6; dir++) {
				int x = i + dl[dir], y = j + dr[dir], z = k + dc[dir];
				if (x < 0  || x >= l || y < 0 || y >= r || z < 0 || z >= c)
					continue;
				if (d[x][y][z] == '#')
					continue;
				if (dist[x][y][z] != INF)
					continue;
				dist[x][y][z] = dist[i][j][k] + 1;
				q.push({x, y, z});
				// printf("%d %d %d, dist = %d\n", x, y, z, dist[x][y][z]);
			}
		}
		if (!found)
			printf("Trapped!\n");
		else
			printf("Escaped in %d minute(s).\n", dist[i][j][k]);
	}
	return 0;
}