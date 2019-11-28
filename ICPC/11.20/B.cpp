#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

typedef vector<int> vi;
typedef long long ll;

ll mypow(int E) {
	ll ret = 1;
	while (E--) {
		ret *= 3;
	}
	return ret;
}

int main() {
	int test;
	scanf("%d", &test);
	while (test--) {
		ll n;
		cin >> n;
		int upperE = int(floor(log(n) / log(3)));
		int E = upperE;
		ll result = n;
		ll prev = 0;
		int avail = -1;
		while (n != 0) {
			if (E < 0)
				break;
			ll sub = mypow(E);
			if (sub <= n) {
				n -= sub;
				prev += sub;
			} else {
				avail = E;
			}
			ll lastMax = (mypow(E) - 1) / 2;
			if (lastMax == n)
				break;
			if (lastMax < n) {
				if (avail == -1)
					result = mypow(upperE+1);
				else
					result = prev + mypow(avail);
				break;
			}
			E--;
		}
		cout << result << endl;
	}
	return 0;
}