#include <bits/stdc++.h>

using namespace std;

int main() {
	int mile;
	char s[100];
	while (scanf("%d %s", &mile, s)) {
		float tank = 0, cap = 0;
		int leak = 0, cons, last = 0;;
		scanf("%s %d", s, &cons);
		if (!cons)
			break;
		while (scanf("%d %s", &mile, s)) {
			tank += (cons/100.0+leak)*(mile-last);
			if (strcmp(s, "Goal") == 0) {
				cap = max(cap, tank);
				break;
			} else if (strcmp(s, "Fuel") == 0) {
				scanf("%s %d", s, &cons);
			} else if (strcmp(s, "Leak") == 0) {
				leak++;
			} else if (strcmp(s, "Gas") == 0) {
				scanf("%s", s);
				cap = max(cap, tank);
				tank = 0;
			} else if (strcmp(s, "Mechanic") == 0) {
				leak = 0;
			}
			last = mile;
		}
		printf("%.3f\n", cap);
	}
	return 0;
}