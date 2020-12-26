#include <cstdio>
#include <iostream>
#include <vector>
#include <string>
#include <queue>
using namespace std;

typedef vector<int> vi;

int main() {
	string s;
	cin >> s;
	int n = s.size();
	vector<vector<int>> v;
	queue<int> zero, one;
	for (int i = 0; i < n; i++) {
		if (s[i] == '0') {
			if (one.empty()) {
				zero.push(v.size());
				v.push_back({i+1});
			} else {
				int index = one.front();
				v[index].push_back(i+1);
				one.pop();
				zero.push(index);
			}
		} else {
			if (zero.empty()) {
				cout << -1 << endl;
				return 0;
			} else {
				int index = zero.front();
				v[index].push_back(i+1);
				zero.pop();
				one.push(index);
			}
		}
	}
	if (!one.empty()) {
		cout << -1 << endl;
		return 0;
	} else {
		cout << v.size() << endl;
		for (int i = 0; i < v.size(); i++) {
			cout << v[i].size();
			for (int j: v[i])
				cout << " " << j;
			cout << endl;
		}
	}
	return 0;
}