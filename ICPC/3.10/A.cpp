#include <cstdio>
#include <iostream>
#include <vector>
#include <string>
#include <set>
using namespace std;

typedef vector<int> vi;

int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		set<char> ret;
		string s;
		cin >> s;
		int n = s.size();
		int i = 0, j = 1;
		while (true) {
			if (i >= n) {
				break;
			} else if (j >= n) {
				ret.insert(s[i]);
				break;
			} else {
				if (s[i] == s[j]) {
					i += 2;
					j += 2;
				} else {
					ret.insert(s[i]);
					i++;
					j++;
				}
			}
		}
		for (char c: ret)
			cout << c;
		cout << endl;
	}
	return 0;
}