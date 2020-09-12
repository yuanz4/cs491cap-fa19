#include <cstdio>
#include <iostream>
#include <vector>
#include <string>
#include <queue>
using namespace std;

typedef long long ll;

ll p = 998244353;

ll binpow(ll a, ll b, ll m) {
	a %= m;
	ll res = 1;
	while (b > 0) {
		if (b & 1)
			res = res * a % m;
		a = a * a % m;
		b >>= 1;
	}
	return res;
}

ll C(ll a, ll b, ll p) {
	if (b > a)
		return 0;
	ll res = 1; 
	for(int i = 1, j = a; i <= b; i++, j--) {
		res = res * j % p;
		res = res * binpow(i,p-2,p) % p;
	}
	return res; 
}

int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	if (n == 2)
		cout << 0 << endl;
	else {
		ll ret = C(m,n-1,p) % p
			* binpow(2,n-3,p) % p
			* (n-2) % p;
		cout << ret << endl;
	}
	return 0;
}