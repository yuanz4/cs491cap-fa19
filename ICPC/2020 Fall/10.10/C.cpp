#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

struct Point {
	ll x, y;
	Point(ll x, ll y) : x(x), y(y){}
};

double dist(Point top, Point left, Point right) {
	double numerator = abs((right.y-left.y)*top.x
		-(right.x-left.x)*top.y
		+right.x*left.y-right.y*left.x);
	double denominator = (right.y-left.y)*(right.y-left.y)
		+(right.x-left.x)*(right.x-left.x);
	denominator = sqrt(denominator);
	return numerator / denominator / 2;
}

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(0);
	int n;
	cin >> n;
	vector<Point> v;
	for (int i = 0; i < n; i++) {
		int x, y;
		cin >> x >> y;
		v.push_back(Point(x, y));
	}
	double ans = DBL_MAX;
	for (int top = 0; top < n; top++) {
		int left = (top-1+n) % n;
		int right = (top+1+n) % n;
		ans = min(ans, dist(v[top], v[left], v[right]));
	}
	cout << setprecision(10) << ans << '\n';
	return 0;
}