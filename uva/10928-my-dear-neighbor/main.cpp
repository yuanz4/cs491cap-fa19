#include <cstdio>
#include <vector>

using namespace std;

int main() {
	int total;
	scanf("%d", &total);
	while (total--) {	
		int place;
		scanf("%d\n", &place);
		char s[10001];
		vector<int> v(place, 0);
		int mini = 100000;
		for (int i = 0; i < place; i++) {
			fgets(s, 10001, stdin);
			int cur = 1;
			for (int j = 0; s[j] != '\n'; j++)
				if (s[j] == ' ')
					cur++;
			v[i] = cur;
			if (cur < mini)
				mini = cur;
		}
		bool first = true;
		for (int i = 0; i < place; i++) {
			if (v[i] == mini) {
				if (first)
					first = false;
				else
					printf(" ");
				printf("%d", i+1);
			}
		}
		printf("\n");
	}
	return 0;
}