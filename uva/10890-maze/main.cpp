#include <stdio.h>
#include <vector>
#include <algorithm>
#include <cstring>
#include <climits>
using namespace std;

int N, S, T;
int ret, U[35];
vector<vector<int>> v;

void dfs(int nd, int cost, int get) {
    if(cost+(N-v[nd][0]+N-v[nd][1]-2) >= ret)
        return;
    if(get == S) {
        ret = min(ret, cost+(N-v[nd][0]+N-v[nd][1]-2));
        return;
    }
    int i;
    for(i = 1; i <= T; i++) {
        if(!U[i]) {
            U[i] = 1;
            dfs(i, cost+abs(v[i][0]-v[nd][0])+abs(v[i][1]-v[nd][1]), get+1);
            U[i] = 0;
        }
    }
}

int main() {
    int i, j, cases = 0;
    while(scanf("%d %d %d", &N, &T, &S), N) {
        int x, y;
        v.clear();
        v.push_back({0, 0});
        for(i = 0; i < T; i++) {
            scanf("%d %d", &x, &y);
            v.push_back({x, y});
        }
        sort(v.begin(), v.end());
        memset(U, 0, sizeof(U));
        ret = INT_MAX;
        dfs(0, 0, 0);
        printf("Case %d: %d\n", ++cases, ret);
    }
    return 0;
}