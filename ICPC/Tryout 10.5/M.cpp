#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    scanf("%d\n", &t);
    while (t--) {
        long long w, g, h, r;
        scanf("%lld %lld %lld %lld\n", &w, &g, &h, &r);
        long double MIN, MAX;
        MIN = sqrt(w*w+(g-h)*(g-h));
        long double lg = g - r;
        long double lh = h - r;
        if (lg == 0 || lh == 0) {
            MAX = MIN;
        } else {
            long double left = w/(lg+lh)*lg;
            long double right = w - left;
            MAX = sqrt(left*left+lg*lg)+sqrt(right*right+lh*lh);
        }
        printf("%Lf %Lf\n", MIN, MAX);
    }
    return 0;
}
