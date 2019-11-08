#include <cstdio>
#include <climits>
using namespace std;

typedef long long ll;

ll x, y, d;

void extendedEuclid(ll a, ll b) {
	if (b == 0) {
		x = 1;
		y = 0;
		d = a;
		return;
	}
	extendedEuclid(b, a % b);
	int x1 = y;
	int y1 = x - (a / b) * y;
	x = x1;
	y = y1;
}

int main() {
	ll n, c1, c2, n1, n2;
	while (scanf("%lld", &n), n) {
		scanf("%lld %lld %lld %lld", &c1, &n1, &c2, &n2);
		extendedEuclid(n1, n2);
		if (n % d != 0) {
			printf("failed\n");
			continue;
		}
		ll factor = n / d;
		ll m1 = x * factor;
		ll m2 = y * factor;
		ll k1 = n1 / d;
		ll k2 = n2 / d;
		if (k2 * c1 > k1 * c2) { // buy second
			ll decay = m1 / k2;
			m1 -= k2 * decay;
			m2 += k1 * decay;
			if (m1 < 0) {
				m1 += k2;
				m2 -= k1;
			}
		} else { // buy first
			ll decay = m2 / k1;
			m1 += k2 * decay;
			m2 -= k1 * decay;
			if (m2 < 0) {
				m1 -= k2;
				m2 += k1;
			}
		}
		if (m1 < 0 || m2 < 0)
			printf("failed\n");
		else
			printf("%lld %lld\n", m1, m2);
	}
	return 0;
}