#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(0);
	int test;
	cin >> test;
	while (test--) {
		int a, b;
		cin >> a >> b;
		int x = 2 * b - a;
		int y = 2 * a - b;
		if (x < 0 || x % 3) {
			cout << "NO" << '\n';
			continue;
		}
		if (y < 0 || y % 3) {
			cout << "NO" << '\n';
			continue;
		}
		cout << "YES" << '\n';
	}
	return 0;
}