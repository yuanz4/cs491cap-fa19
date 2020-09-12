#include <cstdio>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>
using namespace std;

typedef vector<int> vi;

bool sub(string& a, string b) {
	
	return true;
}

int main() {
	int test;
	scanf("%d", &test);
	while (test--) {
		string s, t;
		cin >> s >> t;
		int i = 0, j = 0;
		int op = 1;
		unordered_map<char, int> m;
		for (int i = 0; i < s.size(); i++) {
			if (!m.count(s[i]))
				m[s[i]] = i;
		}
		while (j < t.size()) {
			if (!m.count(t[j]))
				goto fail;
			if (s[i] == t[j]) {
				i++;
				j++;
			} else {
				if (m[t[j]] > i)
					i = m[t[j]];
				else
					i++;
			}
			if (i == s.size() && j < t.size()) {
				op++;
				i = m[t[j]];
			}
		}
		cout << op << endl;
		continue;
		fail:
		cout << -1 << endl;
	}
	return 0;
}