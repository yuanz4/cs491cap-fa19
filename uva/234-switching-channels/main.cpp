#include <bits/stdc++.h>

using namespace std;

void checkMiss(int* prog, int* point, int* impor, int* level,
	int p, int a) {
	int acc[p];
	memcpy(acc, prog, p*sizeof(int));
	for (int i = 1; i < p; i++)
		acc[i] += acc[i-1];

	for (int i = 0; i < a; i++) {
		int low = lower_bound(acc, acc+p, point[i]) - acc;
		int diff;
		if (low == p) {
			diff = abs(acc[p-1]-point[i]);
		} else if (acc[low] == point[i])
			continue;
		else if (low == 0)
			diff = abs(acc[0]-point[i]);
		else {
			int a = abs(acc[low-1]-point[i]);
			int b = abs(acc[low]-point[i]);
			if (a < b)
				diff = a;
			else
				diff = b;
		}
		level[impor[i]] += diff;
	}
}

int main() {
	int p, a;
	int cnt = 1;
	while (scanf("%d", &p), p) {
		int prog[p];
		for (int i = 0; i < p; i++)
			scanf("%d", &prog[i]);
		scanf("%d", &a);
		int impor[a];
		int point[a];
		for (int i = 0; i < a; i++) {
			scanf("%d", &impor[i]);
			impor[i] -= 1;
			scanf("%d", &point[i]);
		}
		sort(prog, prog+p);
		int miss[5];
		for (int i = 0; i < 5; i++)
			miss[i] = INT_MAX;
		int best[p];
		do {
			int level[5] = {};
			checkMiss(prog, point, impor, level, p, a);
			bool better = false;
			for (int i = 0; i < 5; i++) {
				if (level[i] < miss[i]) {
					better = true;
					break;
				} else if (level[i] > miss[i])
					break;
			}
			if (better) {
				memcpy(miss, level, 5*sizeof(int));
				memcpy(best, prog, p*sizeof(int));
			}
		} while (next_permutation(prog, prog+p));
		printf("Data set %d\n", cnt++);
		printf("  Order:");
		for (int i = 0; i < p; i++)
			printf(" %d", best[i]);
		int total = 0;
		for (int i = 0; i < 5; i++)
			total += miss[i];
		printf("\n  Error: %d\n", total);
	}
	return 0;
}