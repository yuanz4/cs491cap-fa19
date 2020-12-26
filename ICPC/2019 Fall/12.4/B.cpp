#include <cstdio>
#include <iostream>
#include <vector>
#include <string>
using namespace std;

typedef vector<int> vi;

int main() {
	string s;
	cin >> s;
	char c = 'z';
	for (int i = 0; i < s.size(); i++) {
		if (s[i] > c)
			printf("Ann\n");
		else
			printf("Mike\n");
		if (s[i] < c)
			c = s[i];
	}
	return 0;
}