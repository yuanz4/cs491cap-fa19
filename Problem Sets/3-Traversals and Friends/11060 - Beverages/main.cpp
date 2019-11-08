#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	int test = 1;
	while (~scanf("%d", &n)) {
		vector<string> v;
		unordered_map<string, int> m;
		string tmp;
		for (int i = 0; i < n; i++) {
			cin >> tmp;
			v.push_back(tmp);
			m[tmp] = i;
		}
		int con;
		scanf("%d", &con);
		unordered_map<int, int> degree;
		unordered_map<int, vector<int>> edge;
		for (int i = 0; i < con; i++) {
			string less, more;
			cin >> less >> more;
			edge[m[less]].push_back(m[more]);
			degree[m[more]]++;
		}
		vector<int> S;
		for (int i = 0; i < n; i++) {
			if (!degree.count(i))
				S.push_back(i);
		}
		vector<int> L;
		while (!S.empty()) {
			sort(S.begin(), S.end(), greater<int>());
			int cur = S.back();
			S.pop_back();
			L.push_back(cur);
			for (int s: edge[cur]) {
				degree[s]--;
				if (!degree[s]) {
					S.push_back(s);
					degree.erase(s);
				}
			}
		}
		printf("Case #%d: Dilbert should drink beverages in this order:", test++);
		for (int s: L) {
			cout << " " << v[s];
		}
		printf(".\n\n");
	}
	return 0;
}