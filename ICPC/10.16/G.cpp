#include <cstdio>
using namespace std;

int main() {
	int test;
	scanf("%d", &test);
	int cur;
	while (test--) {
		scanf("%d", &cur);
		printf("%d\n", cur/2);
	}
	return 0;
}