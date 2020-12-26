#include <cstdio>
#include <cstring>
#include <vector>
#include <iostream>
using namespace std;
 
typedef long long ll;
typedef vector<ll> vi;
const int MX = 100000+7;
 
int main() {
	int n ,m, k;
	while (~scanf("%d %d %d", &n, &m, &k)) {
		ll v[MX];
		for (int i = 1; i <= n; i++)
			cin >> v[i];
		vector<vi> operation(1, vi());
		ll l, r, d;
		for (int i = 0; i < m; i++) {
			cin >> l >> r >> d;
			operation.push_back({l, r, d});
		}
		ll op[MX];
		memset(op, 0, sizeof(op));
		for (int i = 0; i < k; i++) {
			cin >> l >> r;
			op[l] += 1;
			op[r+1] -= 1;
		}
		for (int i = 1; i <= m; i++)
			op[i] += op[i-1];
		ll add[MX];
		memset(add, 0, sizeof(add));
		for (int i = 1; i <= m; i++) {
			l = operation[i][0];
			r = operation[i][1];
			d = operation[i][2] * op[i];
			add[l] += d;
			add[r+1] -= d;
		}
		for (int i = 1; i <= n; i++) {
			add[i] += add[i-1];
			v[i] += add[i];
			if (i != 1)
				printf(" ");
			cout << v[i];
		}
		printf("\n");
	}
	return 0;
}