#include <cstdio>
#include <string>
#include <iostream>
#include <vector>
using namespace std;

int main() {
	int test;
	scanf("%d", &test);
	int n;
	for (int index = 0; index < test; index++) {
		string s;
		cin >> s;
		string odd, even;
		for (char c: s) {
			if ((c-'0') % 2 == 1)
				odd += c;
			else
				even += c;
		}
		int i = 0, j = 0;
		string ret;
		while (i != odd.size() || j != even.size()) {
			if (i == odd.size()) {
				ret += even[j++];
			} else if (j == even.size()) {
				ret += odd[i++];
			} else {
				if (odd[i] < even[j]) {
					ret += odd[i++];
				} else {
					ret += even[j++];
				}
			}
		}
		cout << ret << endl;
	}
	return 0;
}