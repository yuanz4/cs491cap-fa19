#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
#include <unordered_map>
#include <string>
using namespace std;

const int MX = 1000 + 7;
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
		unordered_map<string, int> m;
		LCP[0] = 0;
		int sol = 0;
		string ans;
		for (int i = 1; i < n; i++) {
			int L = 0;
			while (T[SA[i] + L] == T[SA[i-1] + L])
				L++;
			LCP[i] = L;
			if (L) {
				string cur(T, SA[i], L);
				m[cur]++;
				if (L > sol) {
					sol = L;
					ans = cur;
				}
			}
		}
		// for (int i = 0; i < n; i++)
		// 	printf("%d\t%d\t%s\n", SA[i], LCP[i], T + SA[i]);
		if (!sol)
			printf("No repetitions found!\n");
		else
			printf("%s %d\n", ans.c_str(), m[ans]+1);
	}
    return 0;
}