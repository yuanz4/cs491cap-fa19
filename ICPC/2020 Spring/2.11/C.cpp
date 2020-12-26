#include <cstdio>
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int n;
	scanf("%d", &n);
	vector<int> v;
	int tmp;
	for (int i = 0; i < n; i++) {
		scanf("%d", &tmp);
		v.push_back(tmp);
	}
	v.push_back(1e9+1);
	int before_low = 0, high = 0, low = 0;
	int prev, cur;
	bool reverse = false;
	bool used = false;
	for (int i = 0; i <= n; i++) {
		if (i == 0)
			prev = v[0];
		else {
			cur = v[i];
			if (cur < prev) {
				if (used)
					goto end;
				if (!reverse) {
					reverse = true;
					used = true;
					high = i - 1;
					if (i >= 2)
						before_low = v[i-2];
				}
			} else {
				if (!reverse) {
					continue;
				} else {
					reverse = false;
					low = i - 1;
					if (prev < before_low)
						goto end;
					if (v[high] > cur)
						goto end;
				}
			}
			prev = cur;
		}
	}
	printf("yes\n%d %d\n", high+1, low+1);
	return 0;
	end: printf("no\n");
	return 0;
}