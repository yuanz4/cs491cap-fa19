#include <cstdio>
#include <iostream>
using namespace std;

int main() {
	int n, k;
	scanf("%d %d", &n, &k);
	int ten = 0, two = 0, five = 0;
	long long ret = n;
	while (true) {
		if (n % 10 == 0) {
			n /= 10;
			ten++;
		} else if (n % 2 == 0) {
			n /= 2;
			two++;
		} else if (n % 5 == 0) {
			n /= 5;
			five++;
		} else
			break;
	}
	while (ten < k) {
		if (two) {
			two--;
			ret *= 5;
		} else if (five) {
			five--;
			ret *= 2;
		} else
			ret *= 10;
		ten++;
	}
	cout << ret << endl;
	return 0;
}