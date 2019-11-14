#include <cstdio>
#include <math.h>
using namespace std;

bool inCircle(double x, double y, int a) {
	int circleX[] = {0, 0, a, a};
	int circleY[] = {0, a, 0, a};
	for (int i = 0; i < 4; i++) {
		double dist = sqrt(pow(x-circleX[i], 2)+pow(y-circleY[i], 2));
		if (dist > a)
			return false;
	}
	return true;
}

int main() {
	int N, a;
	while (scanf("%d %d", &N, &a), N) {
		double x, y;
		double M = 0;
		for (int i = 0; i < N; i++) {
			scanf("%lf %lf", &x, &y);
			if (inCircle(x, y, a))
				M++;
		}
		printf("%.5lf\n", M*a*a/N);
	}
	return 0;
}