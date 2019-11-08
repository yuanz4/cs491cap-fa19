#include <cstdio>

using namespace std;

int main()
{
	int total;
	scanf("%d", &total);
	int one = 0, two = 0;
	int tmp;
	for (int i = 0; i < total; i++) {
		scanf("%d", &tmp);
		if (tmp == 1)
			one++;
		else
			two++;
	}
	int d[total];
	int i = 0;
	if (two) {
		d[i++] = 2;
		two--;
	}
	if (one) {
		d[i++] = 1;
		one--;
	}
	while (two) {
		d[i++] = 2;
		two--;
	}
	while (one) {
		d[i++] = 1;
		one--;
	}
    for (int i = 0; i < total; i++) {
    	printf("%d", d[i]);
    	if (i != total-1)
    		printf(" ");
    }
    printf("\n");
	return 0;
}