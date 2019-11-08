#include <bits/stdc++.h>

using namespace std;

int main() {
	int n, k;
	scanf("%d %d", &n ,&k);
	int odd = 0, even = 0;
	int tmp;
	for (int i = 0; i < n; i++) {
		scanf("%d", &tmp);
		if (tmp%2 == 1)
			odd++;
		else
			even++;
	}
	int total;
	if (odd%2 == 1)
		total = 1;
	else
		total = 0;
	int step = n-k;
	int each = step/2;
	int common = min(odd, even);
	int left = step-2*common;
	int bigger;
	if (odd < even)
		bigger = 2;
	else if (odd > even)
		bigger = 1;
	else
		bigger = 0;
	bool win = true;
	if (total == 1) {
		if (step%2 == 1) {
			if (left < 0)
				win = true;
			else {
				if (bigger == 2)
					win = true;
				else if (bigger == 1)
					win = false;
				else
					win = true;
			}
		} else {
			if (left < 0)
				win = false;
			else {
				if (bigger == 2)
					win = true;
				else if (bigger == 1)
					win = false;
				else
					win = true;
			}
		}
	} else {
		if (step%2 == 1) {
			if (left < 0)
				win = true;
			else {
				if (bigger == 2)
					win = false;
				else if (bigger == 1)
					win = true;
				else
					win = true;
			}
		} else {
			if (left < 0)
				win = true;
			else {
				if (bigger == 2)
					win = true;
				else if (bigger == 1)
					win = false;
				else
					win = true;
			}
		}
	}
	if (win)
		printf("Stannis\n");
	else
		printf("Daenerys\n");
	return 0;
}