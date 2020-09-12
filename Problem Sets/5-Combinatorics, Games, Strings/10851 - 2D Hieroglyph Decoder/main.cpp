#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;

const int MX = 100;

int main() {
	int test;
	scanf("%d", &test);
	while (test--) {
		char code[10][MX];
		char ret[MX];
		for (int i = 0; i < 10; i++)
			scanf("%s", code[i]);
		int M = strlen(code[0])-2;
		ret[M] = '\0';
		for (int i = 1; i < M+1; i++) {
			int cur = 0;
			for (int j = 8; j >= 1; j--) {
				char tmp = code[j][i];
				cur *= 2;
				if (tmp == '/')
					cur += 0;
				else
					cur += 1;
			}
			ret[i-1] = static_cast<char>(cur);
		}
		printf("%s\n", ret);
	}
	return 0;
}