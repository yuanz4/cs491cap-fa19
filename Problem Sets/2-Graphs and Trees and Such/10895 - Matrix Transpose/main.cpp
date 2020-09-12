#include <bits/stdc++.h>

using namespace std;

bool cmp(vector<int> a, vector<int> b) {
    if (a[0] < b[0])
        return true;
    if (a[0] > b[0])
        return false;
    return a[1] < b[1] ? true : false;
}

int main() {
    int m, n;
    while (scanf("%d %d", &m, &n) != EOF) {
        vector<vector<int>> v;
        int r;
        int colCnt[n+1];
        memset(colCnt, 0, sizeof colCnt);
        for (int i = 1; i <= m; i++) {
            scanf("%d", &r);
            if (!r)
                continue;
            int col[r];
            for (int j = 0; j < r; j++)
                scanf("%d", &col[j]);
            int val;
            for (int j = 0; j < r; j++) {
                scanf("%d", &val);
                v.push_back({col[j], i, val});
                colCnt[col[j]]++;
            }
        }
        sort(v.begin(), v.end(), cmp);
        printf("%d %d\n", n, m);
        int index = 0;
        for (int i = 1; i <= n; i++) {
            printf("%d", colCnt[i]);
            int cur = index;
            for (int j = 0; j < colCnt[i]; j++)
                printf(" %d", v[index++][1]);
            printf("\n");
            for (int j = 0; j < colCnt[i]; j++) {
                if (j)
                    printf(" ");
                printf("%d", v[cur++][2]);
            }
            printf("\n");
        }
    }
    return 0;
}