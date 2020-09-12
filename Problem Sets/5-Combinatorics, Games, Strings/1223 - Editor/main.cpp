#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

const int MX = 5000 + 7;
char T[MX];
int SA[MX], LCP[MX];
int n;

bool cmp(int a, int b) {
	return strcmp(T + a, T + b) < 0;
}

int main() {
	int test;
	scanf("%d", &test);
	while (test--) {
		scanf("%s", T);
		n = strlen(T);
		for (int i = 0; i < n; i++)
			SA[i] = i;
		sort(SA, SA + n, cmp);
		LCP[0] = 0;
		int sol = 0;
		for (int i = 1; i < n; i++) {
			int L = 0;
			while (T[SA[i] + L] == T[SA[i-1] + L])
				L++;
			LCP[i] = L;
			sol = max(sol, L);
		}
		// for (int i = 0; i < n; i++)
		// 	printf("%d\t%d\t%s\n", SA[i], LCP[i], T + SA[i]);
		printf("%d\n", sol);
	}
    return 0;
}