#include <bits/stdc++.h>

using namespace std;

const int MX = 1000+7;
int d[MX];

int Root(int a) {
	if (d[a] != a)
		return d[a] = Root(d[a]);
	return a;
}

void Union(int a, int b) {
	a = Root(a);
	b = Root(b);
	if (a != b)
		d[a] = b;
}

bool Find(int a, int b) {
	return Root(a) == Root(b);
}

int main() {
	int test;
	scanf("%d\n", &test);
	while (test--) {
		int n;
		scanf("%d\n", &n);
		char str[100];
		char type;
		int a, b;
		for (int i = 0; i <= n; i++)
			d[i] = i;
		int con = 0, discon = 0;
		while (fgets(str, 100, stdin)) {
			if (strlen(str) < 3)
				break;
			sscanf(str, "%c %d %d", &type, &a, &b);
			if (type == 'c')
				Union(a, b);
			else {
				if (Find(a, b))
					con++;
				else
					discon++;
			}
		}
		printf("%d,%d\n", con, discon);
		if (test)
			printf("\n");
	}
	return 0;
}