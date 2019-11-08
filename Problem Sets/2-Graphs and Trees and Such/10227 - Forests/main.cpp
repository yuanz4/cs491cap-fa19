#include <bits/stdc++.h>

using namespace std;

int main() {
    int test;
	scanf("%d\n", &test);
	char str[100];
	while (test--) {
		int P, T;
		scanf("%d %d\n", &P, &T);
		vector<unordered_set<int>> s(P, unordered_set<int>());
		int i, j;
		while (fgets(str, 100, stdin)) {
			if (strlen(str) < 3)
				break;
			sscanf(str, "%d %d", &i, &j);
			s[i-1].insert(j);
		}
		vector<string> v(P, "");
		unordered_map<string, int> m;
		for (int i = 0; i < P; i++) {
			for (int x: s[i])
				v[i] += x+'0';
			sort(v[i].begin(), v[i].end());
			m[v[i]]++;
		}
		printf("%lu\n", m.size());
		if (test)
			printf("\n");
	}
    return 0;
}