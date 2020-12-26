#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;
 
int main() {
	int n;
	cin >> n;
	string s, t, p;
	for (int i = 0; i < n; ++i)	{
		cin >> s >> t >> p;
		unordered_map<char, int> m;
		for (char c: p) {
			m[c]++;
		}
		int j = 0;
		for (char c: t) {
			if (j < s.size() && c == s[j]) {
				j++;
			} else if (m.count(c)) {
				m[c]--;
				if (!m[c])
					m.erase(c);
			} else {
				goto next;
			}
		}
		if (j != s.size())
			goto next;
		cout << "YES" << endl;
		continue;
		next:
		cout << "NO" << endl;
	}
	return 0;
};