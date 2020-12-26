#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
    	int h, m;
    	cin >> h >> m;
    	cout << (23-h)*60+60-m << '\n';
    }
	return 0;
}