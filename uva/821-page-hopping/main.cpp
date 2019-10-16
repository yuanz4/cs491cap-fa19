#include <cstdio>
#include <cstring>
#include <algorithm>
#include <unordered_set>
using namespace std;

const int MX = 100+7;
int adj[MX][MX];

int main() {
	int a, b;
	int test = 1;
	while (scanf("%d %d", &a, &b), a) {
		unordered_set<int> s;
		memset(adj, 0x3f, sizeof adj);
		do {
			s.insert(a);
			s.insert(b);
			adj[a][b] = 1;
		} while (scanf("%d %d", &a, &b), a);
		for (int i: s)
			adj[i][i] = 0;
		for (int k: s) {
			for (int i: s) {
				for (int j: s) {
					adj[i][j] = min(adj[i][j], adj[i][k] + adj[k][j]);
				}
			}
		}
		int total = 0;
		for (int i: s) {
			for (int j: s) {
				total += adj[i][j];
			}
		}
		int n = s.size();
		float num = n * (n-1);
		float avg = total / num;
		printf("Case %d: average length between pages = %.3f clicks\n", test++, avg);
	}
	return 0;
}