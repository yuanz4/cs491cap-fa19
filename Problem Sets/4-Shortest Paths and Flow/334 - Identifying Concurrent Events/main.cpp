#include <cstdio>
#include <unordered_map>
#include <vector>
#include <string>
#include <iostream>
using namespace std;

int main() {
	int nc, ne, nm;
	int test = 1;
	while (scanf("%d", &nc), nc) {
		unordered_map<string, unordered_map<string, bool>> adj;
		vector<string> s;
		string tmp, prev;
		for (int i = 0; i < nc; i++) {
			scanf("%d", &ne);
			for (int j = 0; j < ne; j++) {
				cin >> tmp;
				s.push_back(tmp);
				if (j)
					adj[prev][tmp] = true;
				prev = tmp;
			}
		}
		int n = s.size();
		scanf("%d", &nm);
		for (int i = 0; i < nm; i++) {
			cin >> prev >> tmp;
			adj[prev][tmp] = true;
		}
		for (string a: s) {
			for (string b: s) {
				if (!adj[a].count(b))
					adj[a][b] = false;
			}
		}
		for (string k: s) {
			for (string i: s) {
				for (string j: s) {
					adj[i][j] = adj[i][j] | (adj[i][k] & adj[k][j]);
				}
			}
		}
		int ret = 0;
		vector<vector<string>> v;
		for (int i = 0; i < n; i++) {
			for (int j = i+1; j < n; j++) {
				string a = s[i], b = s[j];
				if (!adj[a][b] && !adj[b][a]) {
					ret++;
					if (v.size() < 2)
						v.push_back({a, b});
				}
			}
		}
		if (!ret)
			printf("Case %d, no concurrent events.\n", test++);
		else {
			printf("Case %d, %d concurrent events:\n", test++, ret);
			for (int i = 0; i < min(ret, 2); i++)
				printf("(%s,%s) ", v[i][0].c_str(), v[i][1].c_str());
			printf("\n");
		}
	}
	return 0;
}