#include <cstdio>
#include <iostream>
#include <vector>
#include <string>
using namespace std;

typedef vector<int> vi;

int main() {
	int n;
	scanf("%d", &n);
	string seq;
	cin >> seq;
	string room = "0000000000";
	for (int i = 0; i < n; i++) {
		if (seq[i] == 'L') {
			for (int j = 0; j < 10; j++) {
				if (room[j] == '0') {
					room[j] = '1';
					break;
				}
			}
		} else if (seq[i] == 'R') {
			for (int j = 10; j >= 0; j--) {
				if (room[j] == '0') {
					room[j] = '1';
					break;
				}
			}
		} else {
			room[seq[i]-'0'] = '0';
		}
	}
	cout << room << endl;
	return 0;
}