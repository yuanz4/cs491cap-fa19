#include <cstdio>
#include <iostream>
#include <vector>
#include <string>
using namespace std;

typedef vector<int> vi;

int main() {
	int a, b, c;
	scanf("%d %d %d", &a, &b, &c);
	int ret = 0;
	while (a >= 2 && b >= 2 && c >= 2) {
		ret += (a + b + c - 3) * 2;
		a--;
		b--;
		c--;
	}
	ret += a * b * c;
	cout << ret << endl;
	return 0;
}