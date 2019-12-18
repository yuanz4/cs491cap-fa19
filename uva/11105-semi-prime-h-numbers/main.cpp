#include <cstdio>
#include <cstring>
#include <vector>
#include <unordered_set>
using namespace std;

const int MX = 1000001;
int d[MX+5], v[MX+1];

int main() {
	for (int i = 5; i * i <= MX; i += 4) {
		if (!d[i]) {
			for (int j = i; i * j <= MX; j += 4) {
				d[i*j] = 1;
			}
		}
	}
	int cnt = 0;
	for (int i = 5; i <= MX; i += 4) {
		if (!d[i]) {
			v[cnt++] = i;
		}
	}
	int H;
	while (scanf("%d", &H), H) {
		int visited[H+1] = {0};
		int ans = 0;
		for (int i = 0; i < cnt; i++) {
			if (v[i] * v[i] > H)
				break;
			for (int j = i; j < cnt; j++) {
				int mul = v[i] * v[j];
				if (mul > H)
					break;
				if (mul <= H && !visited[mul]) {
					visited[mul] = 1;
					ans++;
				}
			}
		}
		printf("%d %d\n", H, ans);
	}
	return 0;
}