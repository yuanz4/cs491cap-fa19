#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

typedef vector<int> vi;

int main() {
	int test;
	scanf("%d", &test);
	while (test--) {
		int n;
		scanf("%d", &n);
		int upperE = int(floor(log(n) / log(3)));
		int E = upperE;
		int result = n;
		int prev = 0;
		int avail = -1;
		while (n != 0) {
			if (E < 0)
				break;
			int sub = pow(3, E);
			if (sub <= n) {
				n -= sub;
				prev += sub;
			} else {
				avail = E;
			}
			int lastMax = (pow(3, E) - 1) / 2;
			if (lastMax == n)
				break;
			if (lastMax < n) {
				if (avail == -1)
					result = pow(3, upperE+1);
				else
					result = prev + pow(3, avail);
				break;
			}
			E--;
		}
		printf("%d\n", result);
	}
	return 0;
}