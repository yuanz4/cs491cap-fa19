#include <cstdio>
#include <vector>
#include <math.h>
using namespace std;

#define EPS 1e-9
#define INF 0x3f3f3f3f

struct point {
   double x, y;
   point() { x = y = 0; }
   point(double _x, double _y) : x(_x), y(_y) {}
   bool operator==(const point& other) {
     return fabs(x - other.x) < EPS && fabs(y - other.y) < EPS;
   }
   bool operator<(const point& other) {
     if (fabs(x - other.x) < EPS)
        return y < other.y;
     else return x < other.x;
  }
};

struct vec {
   double x, y;
   vec(double _x, double _y) : x(_x), y(_y) {}
};

vec toVec(point a, point b) {
   return vec(b.x - a.x, b.y - a.y);
}
vec scale(vec v, double s) {
   return vec(v.x * s, v.y * s);
}

point translate(point p, vec v) {
   return point(p.x + v.x , p.y + v.y);
}

double dot(vec a, vec b) {
   return (a.x * b.x + a.y * b.y);
}
double norm_sq(vec v) {
   return v.x * v.x + v.y * v.y;
}

double dist(point &a, point &b) {
   double dx=a.x-b.x;
   double dy=a.y-b.y;
   return sqrt(dx * dx + dy * dy);
}

double distToLineSegment(point p, point a, point b, point &c) {
   vec ap = toVec(a, p), ab = toVec(a, b);
   double u = dot(ap, ab) / norm_sq(ab);
   if (u < 0.0) {
      c = point(a.x, a.y);
      return dist(p, a);
   }
   if (u > 1.0) {
      c = point(b.x, b.y);
      return dist(p, b); }
   c = translate(a, scale(ab, u));
   return dist(p, c);
}

int main() {
	double x, y;
	while (~scanf("%lf %lf", &x, &y)) {
		point p = point(x, y);
		int N;
		scanf("%d", &N);
		point a = point(x, y);
		double mini = INF;
		point ret;
		for (int i = 0; i < N+1; i++) {
			scanf("%lf %lf", &x, &y);
			point b = point(x, y);
			if (i) {
				point c = point(0, 0);
				double cur = distToLineSegment(p, a, b, c);
				if (cur < mini) {
					ret = c;
					mini = cur;
				}
			}
			a = b;
		}
		printf("%.4lf\n%.4lf\n", ret.x, ret.y);
	}
	return 0;
}