#include <cstdio>
#include <algorithm>
using namespace std;

int main() {
	long R, x1, y1, x2, y2;
	double xap, yap, r;
	scanf("%ld %ld %ld %ld %ld", &R, &x1, &y1, &x2, &y2);
	double dist = sqrt(pow(x1-x2, 2)+pow(y1-y2, 2));
	if (dist >= R) {
		r = R, xap = x1, yap = y1;
	} else {
		r = (dist + R) / 2;
		if (dist != 0) {
			xap = (x1-x2)/dist*r+x2;
			yap = (y1-y2)/dist*r+y2;
		} else {
			xap = x1+r;
			yap = y1;
		}
	}
	printf("%lf %lf %lf\n", xap, yap, r);
	return 0;
}