#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
 
int gcd(int a, int b) {
	if (b == 0)
		return a;
	return gcd(b, a % b);
}
 
int main() {
	int test;
	scanf("%d", &test);
	int a, b;
	while (test--) {
		scanf("%d %d", &a, &b);
		if (gcd(a, b) == 1)
			printf("Finite\n");
		else
			printf("Infinite\n");
	}
	return 0;
}