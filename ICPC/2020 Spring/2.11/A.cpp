#include <cstdio>
#include <iostream>
#include <vector>
#include <string>
using namespace std;

typedef vector<int> vi;

int main() {
	int t;
	scanf("%d", &t);
	long long A, B;
	while (t--) {
		scanf("%lld %lld", &A, &B);
		long long digit = 0;
		B += 1;
		while (B >= 10) {
			digit++;
			B /= 10;
		}
		cout << A * digit << endl;
	}
	return 0;
}