#include <bits/stdc++.h>

using namespace std;

int main() {
	int N, n = 0;
	char s[100];
	while (scanf("%d", &N), N) {
		if (n++)
			printf("\n");
		int f = 0;
		for (int fghij = 1234; fghij < 99999; fghij++) {
			int abcde = fghij * N;
			sprintf(s, "%05d%05d", abcde, fghij);
			if (strlen(s) > 10)
				break;
			sort(s, s+10);
			bool b = true;
			for (int i = 0; i < 10; i++) {
				if (s[i] != i+'0')
					b = false;
			}
			if (b) {
				f++;
				printf("%05d / %05d = %d\n", abcde, fghij, N);
			}
		}
		if(f==0)
			printf("There are no solutions for %d.\n", N);
	}
	return 0;
}
