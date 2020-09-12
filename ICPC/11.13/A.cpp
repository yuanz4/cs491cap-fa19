#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef vector<int> vi;

int main() {
	int test;
	scanf("%d", &test);
	while (test--) {
		int n;
		scanf("%d", &n);
		vi v;
		int tmp;
		for (int i = 0; i < n; i++) {
			scanf("%d", &tmp);
			v.push_back(tmp);
		}
		int expect = 1;
		int i = 0;
		while (i < n) {
			if (v[i] == expect) {
				i++;
				if (i < n) {
					expect = v[i];
					for (int k = i+1; k < n; k++)
						expect = min(expect, v[k]);
				}
				continue;
			}
			for (int j = i+1; j < n; j++) {
				if (v[j] == expect) {
					for (int k = j-1; k >= i; k--)
						swap(v[k], v[k+1]);
					i = j;
					if (i < n) {
						expect = v[i];
						for (int k = i+1; k < n; k++)
							expect = min(expect, v[k]);
					}
					goto next;
				}
			}
			next:;
		}
		for (int i = 0; i < n; i++) {
			if (i)
				printf(" ");
			printf("%d", v[i]);
		}
		printf("\n");
	}
	return 0;
}