#include <bits/stdc++.h>

using namespace std;
 
int f(int x) {
    return x * 1000 + x % 10 * 100 + x / 10 % 10 * 10 + x / 100;
}
 
int main() {
    int n, a, b, ans;
    cin >> n;
    while (n--) {
        cin >> a;
        b = a / 1000, ans = b;
        if (b < 999 && abs(f(ans) - a) > abs(f(b + 1) - a))
            ans = b + 1;
        if (b > 100 && abs(f(ans) - a) >= abs(f(b - 1) - a))
            ans = b - 1;
        cout << f(ans) << endl;
    }
    return 0;
}

// 7
// 119871
// 108993
// 199191
// 108991
// 109995
// 198999
// 190111
