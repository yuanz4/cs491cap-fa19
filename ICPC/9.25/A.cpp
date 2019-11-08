#include <bits/stdc++.h>

using namespace std;

int main() {
	int n;
	scanf("%d", &n);
	unordered_set<int> s;
	vector<int> v(n, 0);
	for (int i = 0; i < n; i++)
		scanf("%d", &v[i]);
	vector<int> output;
	for (int i = n-1; i >= 0; i--) {
		if (s.count(v[i]))
			continue;
		output.push_back(v[i]);
		s.insert(v[i]);
	}
	printf("%lu\n", output.size());
	for (int i = output.size()-1; i >= 0; i--) {
		printf("%d", output[i]);
		if (i)
			printf(" ");
	}
	printf("\n");
	return 0;
}