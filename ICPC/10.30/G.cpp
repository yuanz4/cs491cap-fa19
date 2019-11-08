#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
 
int main() {
	int n;
	cin >> n;
	vector<int> v(n, 0);
	long long sum = 0;
	for (int i = 0; i < n; ++i)	{
		cin >> v[i];
		sum += v[i];
	}
	sort(v.begin(), v.end());
	long long a = 0, b = 0;
	for (int i = 0; i < n/2; ++i) {
		a += v[i];
	}
	b = sum - a;
	long long ret = b*b + a*a;
	cout << ret << endl;
}