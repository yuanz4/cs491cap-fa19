#include <cstdio>
#include <string>
#include <iostream>
#include <vector>
#include <set>
#include <unordered_map>
using namespace std;

int main() {
	int m, n;
	scanf("%d %d", &n, &m);
	unordered_map<int, int> d;
	vector<set<int>> v;
	int a, b;
	for (int i = 0; i < m; i++) {
		scanf("%d %d", &a, &b);
		if (d.count(a) && !d.count(b)) {
			v[d[a]].insert(b);
			d[b] = d[a];
		} else if (d.count(b) && !d.count(a)) {
			v[d[b]].insert(a);
			d[a] = d[b];
		} else if (d.count(a) && d.count(b)) {
			if (d[a] != d[b]) {
				// cout << a << " " << b << endl;
				int smaller = min(d[a], d[b]);
				int bigger = max(d[a], d[b]);
				// cout << smaller << " " << bigger << endl;
				for (int j: v[bigger]) {
					v[smaller].insert(j);
					d[j] = smaller;
				}
				// v.erase(v.begin()+bigger);
			}
		} else {
			d[a] = d[b] = v.size();
			v.push_back(set<int>({a, b}));
		}
	}
	// for (auto i: v) {
	// 	for (int j: i)
	// 		cout << j << " ";
	// 	cout << endl;
	// }
	int ret = 0;
	int i = 1;
	while (i <= n) {
		if (!d.count(i)) {
			i++;
		} else {
			for (int j = i+1; j < *v[d[i]].rbegin(); j++) {
				if (!d.count(j)) {
					ret++;
				} else {
					if (d[j] != d[i]) {
						ret++;
						for (int k: v[d[j]]) {
							d[k] = d[i];
							v[d[i]].insert(k);
						}
					}
				}
			}
			i = *v[d[i]].rbegin() + 1;
		}
	}
	cout << ret << endl;
	return 0;
}