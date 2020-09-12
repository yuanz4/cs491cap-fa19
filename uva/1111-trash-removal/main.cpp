#include <cstdio>
#include <cstring>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

#define EPS 1E-9
#define INF 0x3f3f3f3f
int n;

struct point {
	double x, y;
	point() {x = y = 0;}
	point(double _x, double _y) : x(_x), y(_y) {}
};

point pivot;

struct vec {
	double x, y;
	vec(double _x, double _y) : x(_x), y(_y) {}
};

vec toVec(point a, point b) {
	return vec(b.x - a.x, b.y - a.y);
}

double cross(vec a, vec b) {
	return (a.x * b.y - a.y * b.x);
}

bool collinear(point p, point q, point r) {
	return fabs(cross(toVec(p, q), toVec(p, r))) < EPS;
}

double dist(point &a, point &b) {
   double dx=a.x-b.x;
   double dy=a.y-b.y;

   return sqrt(dx * dx + dy * dy);
}

vec scale(vec v, double s) {
   return vec(v.x * s, v.y * s);
}

double dot(vec a, vec b) {
	return (a.x * b.x + a.y * b.y);
}

double norm_sq(vec v) {
	return v.x * v.x + v.y * v.y;
}

point translate(point p, vec v) {
	return point(p.x + v.x , p.y + v.y);
}

double distToLine(point p, point a, point b) {
	vec ap = toVec(a, p), ab = toVec(a, b);
	double u = dot(ap, ab) / norm_sq(ab);
	point c = translate(a, scale(ab, u));
	return dist(p, c);
}

bool ccw(point p, point q, point r) {
	return cross(toVec(p, q), toVec(p, r)) > EPS;
}

bool angleCmp(point a, point b) {
	if (collinear(pivot, a, b))
		return dist(pivot, a) < dist(pivot, b);
	double d1x = a.x - pivot.x, d1y = a.y - pivot.y;
	double d2x = b.x - pivot.x, d2y = b.y - pivot.y;
	return (atan2(d1y, d1x) - atan2(d2y, d2x)) < 0;
}

int main() {
	int test = 1;
	while (scanf("%d", &n), n) {
		vector<point> P;
		double x, y;
		for (int i = 0; i < n; i++) {
			scanf("%lf %lf", &x, &y);
			P.push_back(point(x, y));
		}
		int P0 = 0;
		for (int i = 1; i < n; i++)
			if (P[i].y < P[P0].y || (P[i].y == P[P0].y && P[i].x > P[P0].x))
				P0 = i;
		swap(P[0], P[P0]);
		pivot = P[0];
		sort(++P.begin(), P.end(), angleCmp);
		vector<point> S;
		S.push_back(P[n-1]);
		S.push_back(P[0]);
		S.push_back(P[1]);
		int i = 2;
		while (i < n) {
			int j = S.size()-1;
			if (ccw(S[j-1], S[j], P[i]))
				S.push_back(P[i++]);
			else
				S.pop_back();
		}
		int m = S.size();
		double ret = INF;
		for (i = 0; i < m-1; i++) {
			double cur = 0;
			for (int j = 0; j < m-1; j++) {
				if (j == i || j == i+1 || (i+1 == m-1 && j == 0))
					continue;
				// printf("%lf\n", distToLine(S[j], S[i], S[i+1]));
				cur = max(cur, distToLine(S[j], S[i], S[i+1]));
			}
			ret = min(cur, ret);
		}
		printf("Case %d: %.2lf\n", test++, ret);
		// for (point p: S) {
		// 	printf("%lf %lf\n", p.x, p.y);
		// }
	}
	return 0;
}