#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

ll gcd(ll m, ll n) {
    ll t = 1;
    while(t != 0) {
        t=m % n;
        m=n;
        n=t;
    }
    return m;
}

int main() {
    ll m, n;
    scanf("%lld %lld", &m, &n);
    ll g = gcd(m, n);
    ll mg = m / g;
    ll ng = n / g;
    ll total = 0;
    if (ng % 2 != 0 && mg % 2 != 0)
    	total = g;
    printf("%lld\n", total);
    return 0;
}
