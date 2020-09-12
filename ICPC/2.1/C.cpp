#include <cstdio>
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

typedef long long ll;

int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	int a[n];
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	sort(a, a+n);
	ll acc[n];
	for (int i = 0; i < n; i++) {
		if (i < m)
			acc[i] = a[i];
		else
			acc[i] = acc[i-m] + a[i];
	}
	ll x[n+1];
	memset(x, 0, sizeof(x));
	for (int i = 1; i <= n; i++) {
		x[i] = x[i-1] + acc[i-1];
	}
	for (int i = 1; i <= n; i++) {
		if (i == n)
			cout << x[i] << endl;
		else
			cout << x[i] << ' ';
	}
	return 0;
}