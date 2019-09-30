#include <bits/stdc++.h>

using namespace std;

int main() {
	unsigned N, L, U, M;
	while (scanf("%u %u %u", &N, &L, &U) != EOF) {
		M = 0u;
		unsigned mask;
		for (int i = 31; i >= 0; i--) {
			mask = 1u<<i;
			unsigned cur = M | mask;
			if (N & mask) {
				if (cur <= L)
					M = cur;
			} else {
				if (cur <= U)
					M = cur;
			}
		}
		printf("%u\n", M);
	}
	return 0;
}