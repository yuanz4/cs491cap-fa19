#include <cstdio>
#include <iostream>
#include <vector>
#include <string>
using namespace std;

typedef vector<int> vi;

int main() {
	int t;
	scanf("%d", &t);
	int n;
	while (t--) {
		scanf("%d", &n);
		int b = n / 2;
		if (n % 2 == 1) {
			printf("7");
			b--;
		}
		while (b--)
			printf("1");
		printf("\n");
	}
	return 0;
}