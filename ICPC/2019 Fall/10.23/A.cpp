#include <cstdio>
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

vector<string> ret;
int n;

bool palindrome(string& s) {
	string rev = s;
	reverse(rev.begin(), rev.end());
	if (rev == s)
		return true;
	return false;
}

void backTrack(string& s, string& cur, int index) {
	if (index == n) {
		if (!cur.empty() && palindrome(cur))
			ret.push_back(cur);
		return;
	}
	for (int i = index; i < n; i++) {
		backTrack(s, cur, i+1);
		cur += s[i];
		backTrack(s, cur, i+1);
		cur.pop_back();
	}
}

int main() {
	string s;
	cin >> s;
	n = s.size();
	string cur;
	backTrack(s, cur, 0);
	make_heap(ret.begin(), ret.end());
	cout << ret[0] << endl;
	return 0;
}