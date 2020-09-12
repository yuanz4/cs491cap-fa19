#include <bits/stdc++.h>

using namespace std;

#define lft at<<1
#define ryt at<<1|1
const int MX = 100000;
int T_max[MX<<2], T_min[MX<<2], lazy[MX<<2];
int total;

void propagate(int at, int l, int r) {
    if (lazy[at] && l != r) {
        T_max[lft] = T_min[lft] = lazy[lft] = lazy[at];
        T_max[ryt] = T_min[ryt] = lazy[ryt] = lazy[at];
        lazy[at] = 0;
    }
}

void query(int at, int l, int r, int& x, int& y, int& h) {
    if(x > r || y < l)
        return;
    if (h < T_min[at])
        return;
    propagate(at, l, r);
    if(x <= l && y >= r) {
        if (h >= T_max[at]) {
            T_max[at] = T_min[at] = lazy[at] = h;
            total += r-l+1;
            return;
        }
    }
    if (l != r) {
        int mid = (l+r) >> 1;
        query(lft, l, mid, x, y, h);
        query(ryt, mid+1, r, x, y, h);
        T_max[at] = max(T_max[lft], T_max[ryt]);
        T_min[at] = min(T_min[lft], T_min[ryt]);
    }
}

int main() {
    int c;
    scanf("%d", &c);
    while (c--) {
        int n;
        scanf("%d", &n);
        if (!n)
            break;
        int x, y, h;
        total = 0;
        memset(T_max, 0, sizeof(T_max));
        memset(T_min, 0, sizeof(T_min));
        memset(lazy, 0, sizeof(lazy));
        for (int i = 0; i < n; i++) {
            scanf("%d %d %d", &x, &y, &h);
            y--;
            query(1, 1, MX, x, y, h);
        }
        printf("%d\n", total);
    }
    return 0;
}