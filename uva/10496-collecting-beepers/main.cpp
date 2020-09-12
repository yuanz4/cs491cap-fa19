#include <algorithm>
#include <iostream>
#include <cmath>
#include <cstring>
#include <climits>
using namespace std;

int i, j, TC, xsize, ysize, n, x[11], y[11], dist[11][11], memo[11][1 << 11];

int tsp(int pos, int bitmask) {
    if (bitmask == (1 << (n + 1)) - 1)
        return dist[pos][0];
    if (memo[pos][bitmask] != -1)
        return memo[pos][bitmask];

    int ans = INT_MAX;
    for (int nxt = 0; nxt <= n; nxt++)
        if (nxt != pos && !(bitmask & (1 << nxt)))
            ans = min(ans, dist[pos][nxt] + tsp(nxt, bitmask | (1 << nxt)));
    return memo[pos][bitmask] = ans;
}

int main() {
    scanf("%d", &TC);
    while (TC--) {
        scanf("%d %d", &xsize, &ysize);
        scanf("%d %d", &x[0], &y[0]);
        scanf("%d", &n);
        for (i = 1; i <= n; i++)
            scanf("%d %d", &x[i], &y[i]);

        for (i = 0; i <= n; i++)
            for (j = 0; j <= n; j++)
                dist[i][j] = abs(x[i] - x[j]) + abs(y[i] - y[j]);

        memset(memo, -1, sizeof memo);
        printf("The shortest path has length %d\n", tsp(0, 1));
    }
    return 0;
}