#include <cstdio>
#include <vector>
#include <string>
#include <iostream>
using namespace std;

vector<string> v;

bool checkWin(char p) {
	for (int i = 0; i < 4; i++) {
		int row = 0, col = 0;
		for (int j = 0; j < 4; j++) {
			row += v[i][j] == p;
			col += v[j][i] == p;
		}
		if (row == 4 || col == 4)
			return true;
	}
	int left = 0, right = 0;
	for (int i = 0; i < 4; i++) {
		left += v[i][i] == p;
		right += v[3-i][i] == p;
	}
	if (left == 4 || right == 4)
		return true;
	return false;
}

int play(int x) {
	char c = x == 1 ? 'x' : 'o';
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			if (v[i][j] == '.') {
				v[i][j] = c;
				if (checkWin(c) || play(1-x) == -1) {
					v[i][j] = '.';
					return i*4+j;
				}
				v[i][j] = '.';
			}
		}
	}
	return -1;
}

int main() {
	char c;
	while (scanf(" %c", &c), c != '$') {
		v.clear();
		string s;
		for (int i = 0; i < 4; i++) {
			cin >> s;
			v.push_back(s);
		}
		int ret = play(1);
		if (ret == -1)
			printf("#####\n");
		else
			printf("(%d,%d)\n", ret/4, ret%4);
	}
	return 0;
}