#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, m;
    while (scanf("%d %d", &n, &m), n) {
        vector<vector<int>> v(n, vector<int>());
        unordered_set<int> suspect;
        suspect.insert(0);
        unordered_set<int> checked;
        unordered_set<int> del;
        vector<unordered_set<int>> group(m, unordered_set<int>());
        int k, tmp;
        for (int i = 0; i < m; i++) {
            scanf("%d", &k);
            while (k--) {
                scanf("%d", &tmp);
                group[i].insert(tmp);
                v[tmp].push_back(i);
            }
        }
        int size;
        while (true) {
            size = suspect.size();
            for (int i: suspect) {
                if (checked.count(i))
                    continue;
                checked.insert(i);
                for (int j = 0; j < v[i].size(); j++) {
                    if (del.count(v[i][j]))
                        continue;
                    del.insert(v[i][j]);
                    for (int k: group[v[i][j]])
                        suspect.insert(k);
                }
            }
            if (size == suspect.size())
                break;
        }
        printf("%d\n", size);
    }
    return 0;
}