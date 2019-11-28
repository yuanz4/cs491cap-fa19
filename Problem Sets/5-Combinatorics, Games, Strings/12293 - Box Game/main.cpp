#include <cstdio>
#include <iostream>
using namespace std;

bool pow2(int i) {
	while (i != 1) {
		if ((i & 1) == 0)
			return false;
		i >>= 1;
	}
	return true;
}

int main() {
	int n;
	while (scanf("%d", &n), n) {
		if (pow2(n))
			printf("Bob\n");
		else
			printf("Alice\n");
	}
	return 0;
}