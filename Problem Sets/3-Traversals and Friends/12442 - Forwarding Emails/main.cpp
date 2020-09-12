#include <vector>
#include <cstdio>
using namespace std;

vector<bool> visited;
vector<int> num, graph;

void dfs(int i) {
	visited[i] = true;
	int next = graph[i];
	if (!visited[next])
		dfs(next);
	else if (!num[next]){
		int cnt = 0;
		int start = next;
		do {
			cnt++;
			start = graph[start];
		} while (start != next);
		start = next;
		do {
			num[start] = cnt;
			start = graph[start];
		} while (start != next);
	}
	if (!num[i])
		num[i] = 1 + num[next];
}

int main() {
	int test;
	scanf("%d", &test);
	for (int t = 1; t <= test; t++) {
		int n;
		scanf("%d", &n);
		visited.assign(n, false);
		num.assign(n, 0);
		graph.assign(n, 0);
		int a, b;
		for (int i = 0; i < n; i++) {
			scanf("%d %d", &a, &b);
			graph[a-1] = b-1;
		}
		int ret, best = 0;
		for (int i = 0; i < n; i++) {
			if (!visited[i])
				dfs(i);
			if (num[i] > best) {
				best = num[i];
				ret = i;
			}
		}
		// for (int i = 0; i < n; i++)
		// 	printf("%d ", num[i]);
		// printf("\n");
		printf("Case %d: %d\n", t, ret+1);
	}
	return 0;
}