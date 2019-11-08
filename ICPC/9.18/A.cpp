#include <cstdio>

using namespace std;

int main() {
	int num;
	scanf("%d", &num);
	int a, b, c;
	if (num%3 == 0) {
		a = 1;
		b = 1;
		c = num-2;
	} else if (num%3 == 1) {
		a = 1;
		b = 2;
		c = num-3;
	} else {
		a = 1;
		b = 2;
		c = num-3;
	}
	printf("%d %d %d\n", a, b, c);
	return 0;
}

// int main() {
// 	int num;
// 	scanf("%d", &num);
// 	int a, b, c;
// 	a = b = c = num / 3;
// 	int left = num-num/3*3;
// 	if (a%3 == 0) {
// 		if (left == 0) {
// 			a--;
// 			b--;
// 			c += 2;
// 		} else if (left == 1) {
// 			a++;
// 			b++;
// 			c--;
// 		} else {
// 			a--;
// 			b++;
// 			c += 2;
// 		}
// 	} else {
// 		if (left == 1) {
// 			if ((a+1)%3 == 0) {
// 				a += 2;
// 				b--;
// 			} else {
// 				a++;
// 			}
// 		} else if (left == 2) {
// 			if ((a+1)%3 == 0) {
// 				a += 2;
// 			} else {
// 				a++;
// 				b++;
// 			}
// 		}
// 	}
// 	printf("%d %d %d\n", a, b, c);
// 	return 0;
// }