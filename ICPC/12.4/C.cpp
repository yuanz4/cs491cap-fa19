#include <cstdio>
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int test;
	scanf("%d", &test);
	int n;
	for (int index = 0; index < test; index++) {
		scanf("%d", &n);
		string s;
		vector<string> v(n, "");
		for (int i = 0; i < n; i++) {
			cin >> s;
			v[i] = s;
		}
		sort(v.begin(), v.end());
		int ret = 0;
		int count = 0;
		for (int i = 0; i < n-1; i++) {
			if (v[i] == v[i+1]) {
				count++;
			} else {
				if (count != 0) {
					ret += count;
					count = 0;
				}
			}
		}
		ret += count;
		cout << ret << endl;
	}
	return 0;
}