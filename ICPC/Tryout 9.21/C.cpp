#include <bits/stdc++.h>

using namespace std;

int main() {
    int mod = 998244353;
    int N = 1e3 + 5;
    unordered_map<long, long> m;
    int cnt[N], total = 0, tmp;
    long long d[N][N];
    int n, k;
    scanf("%d %d", &n, &k);
    for (int i = 0; i < n; i++) {
        scanf("%d", &tmp);
        if (!m.count(tmp)) {
            m[tmp] = ++total;
            cnt[total] = 1;
        } else {
            cnt[m[tmp]]++;
        }
    }
    for (int i = 1; i <= total; i++) {
        cout << cnt[i] << endl;
    }
    d[0][0] = 1;
    cout << d[0][1] << d[0][2] << d[0][3] << endl;
    for (int i = 1; i <= total; i++) {
        for (int j = 0; j <= k; j++)
            d[i][j] = d[i-1][j];
        for (int j = 1; j <= k; j++)
            d[i][j] = (d[i][j]+d[i-1][j-1]*cnt[i]) % mod;
    }
    printf("%lld\n", d[total][k]);
    return 0;
}
