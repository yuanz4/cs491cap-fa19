#include <bits/stdc++.h>
using namespace std;

const int MX = 200+7;
int n;
bool found;

bool check(unordered_map<char, unordered_set<char>> p, vector<char>& ret, char cur) {
	for (char c: ret) {
		if (p[cur].count(c))
			return false;
	}
	return true;
}

void backTracking(vector<char>& v, unordered_map<char, unordered_set<char>> p,
	vector<char>& ret, vector<int>& stat) {
	if (ret.size() == n) {
		for (int i = 0; i < n; i++) {
			if (i)
				printf(" ");
			printf("%c", ret[i]);
		}
		printf("\n");
		found = true;
		return;
	}
	int next = 0;
	for (; next < n; next++) {
		if (!stat[next]) {
			char cur = v[next];
			if (ret.empty()) {
				goto valid;
			} else {
				char back = ret.back();
				if (p.count(cur) && !check(p, ret, cur)) // not valid
					return;
			}
			valid:
			stat[next] = 1;
			ret.push_back(cur);
			backTracking(v, p, ret, stat);
			stat[next] = 0;
			ret.pop_back();
		}
	}
}

int main() {
	int test;
	scanf("%d", &test);
	char var[MX];
	char constraint[MX];
	fgets(var, MX, stdin);
	while (test--) {
		fgets(var, MX, stdin);
		fgets(var, MX, stdin);
		fgets(constraint, MX, stdin);
		vector<char> v;
		for (int i = 0; i < strlen(var); i++) {
			if (var[i] >= 'A' && var[i] <= 'Z')
				v.push_back(var[i]);
		}
		unordered_map<char, unordered_set<char>> p;
		int i = 0;
		while (i < strlen(constraint)) {
			if (constraint[i] >= 'A' && constraint[i] <= 'Z') {
				char cur = constraint[i];
				i += 2;
				p[cur].insert(constraint[i]);
			}
			i++;
		}
		n = v.size();
		vector<int> stat(n, 0);
		vector<char> ret;
		found = false;
		backTracking(v, p, ret, stat);
		if (!found)
			printf("NO\n");
		if (test)
			printf("\n");
	}
	return 0;
}