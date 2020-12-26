#include <cstdio>
#include <string>
#include <iostream>
#include <vector>
#include <set>
#include <unordered_map>
using namespace std;

int main() {
	int m, n;
	scanf("%d %d", &n, &m);
	int x[n], s[n];
	for (int i = 0; i < n; i++)
		scanf("%d %d", &x[i], &s[i]);
	int d[m+1];
	d[0] = 0;
	for (int i = 1; i <= m; i++) {
		d[i] = d[i-1] + 1;
		for (int j = 0; j < n; j++) {
			int x_ = x[j];
			int s_ = s[j];
			if (x_ <= i) {
				if (x_ + s_ >= i)
					d[i] = min(d[i], d[max(0, x_-s_-1)]);
				else
					d[i] = min(d[i], i-x_-s_+d[max(0, 2*x_-i-1)]);
			} else {
				if (x_ - s_ <= i)
					d[i] = min(d[i], d[max(0, x_-s_-1)]);
			}
		}
	}
	cout << d[m] << endl;
	return 0;
}