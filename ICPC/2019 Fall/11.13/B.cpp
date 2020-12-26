#include <cstdio>
#include <cstring>
#include <vector>
#include <iostream>
using namespace std;
 
typedef vector<int> vi;
 
int main() {
	int  n, k, x;
	scanf("%d %d %d", &n, &k, &x);
	vi v(n, 0);
	for (int i = 0; i < n; i++)
		scanf("%d", &v[i]);
	if (k*(x+1)-1 < v.size()) {
		printf("-1\n");
		return 0;
	}
	long d[x+1][n];
	memset(d, -1, sizeof(d));
	d[0][0] = 0;
	for (int i = 1; i < x+1; i++) {
		for (int j = 0; j < n; j++) {
			for (int l = max(0, i-1); l < min(i+k, n); l++) {
				d[i][l] = v[l];
				for (int p = max(0, l-3); p < l; p++) {
					if (d[i-1][p] != -1)
						d[i][l] = max(d[i][l], v[l]+d[i-1][p]);
				}
			}
		}
	}
	long biggest = -1;
	for (int i = 0; i < n; i++)
		biggest = max(biggest, d[x][i]);
	printf("%ld\n", biggest);
	return 0;
}