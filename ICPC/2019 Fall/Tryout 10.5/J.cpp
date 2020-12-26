#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

int main() {
    int n;
    scanf("%d\n", &n);
    ll d[n+1];
    d[0] = 0;
    int con[n+1];
    memset(con, 0, sizeof con);
    ld total = 0;
    for (size_t i = 1; i <= n; i++) {
        scanf("%lld", &d[i]);
        total += d[i];
    }
    ld ret = total / n;
    for (size_t i = 1; i <= n; i++) {
        ld ret_i, ret_ii;
        ll addv = d[i]+d[i-1];
        int addc = con[i-1]+1;
        if (n-1 == 0) {
            ret_i = 0;
        } else {
            ret_i = (total-d[i]) / (n-1);
        }
        if (n-addc == 0) {
            ret_ii = 0;
        } else {
            ret_ii = (total-addv) / (n-addc);
        }
        if (ret_i > ret_ii) {
            con[i] = 1;
            if (ret_i > ret) {
                ret = ret_i;
            }
        } else {
            d[i] = d[i]+d[i-1];
            con[i] = con[i-1]+1;
            if (ret_ii > ret) {
                ret = ret_ii;
            }
        }
    }
    printf("%Lf\n", ret);
    return 0;
}
