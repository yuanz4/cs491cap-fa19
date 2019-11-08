#include <bits/stdc++.h>

using namespace std;

int main() {
	int a, b, c;
	scanf("%d %d %d", &a, &b, &c);
	int mx = 100000;
	int i = 1;
	while (mx--) {
		a *= 10;
		if (a/b == c)
			break;
		a %= b;
		i++;
	}
	if (mx == -1)
		printf("-1\n");
	else
		printf("%d\n", i);
	return 0;
}