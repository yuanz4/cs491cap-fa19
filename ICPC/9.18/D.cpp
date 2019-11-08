#include <cstdio>

using namespace std;


int main() {
	int n, k;
	scanf("%d %d", &n, &k);
	int d[n];
	for (int i = 0; i < n; i++)
		scanf("%d", &d[i]);
	long sum = 0;
	int right = n-1;
	while (k) {
		if (k == 1) {
			for (int i = 0; i <= right; i++)
				sum += d[i];
		} else {
			int left = k-1;
			long best = d[right];
			long acc = d[right];
			int stop = right;
			for (int i = right-1; i >= left; i--) {
				acc += d[i];
				if (acc > best) {
					best = acc;
					stop = i;
				}
			}
			sum += best*k;
			right = stop-1;
		}
		k--;
	}
	printf("%ld\n", sum);
	return 0;
}