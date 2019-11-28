#include <iostream>
#include <string>
#include <vector>
#include <cstdio>
#include <unordered_set>
#include <queue>
#include <algorithm>
using namespace std;

int n;

bool find(queue<string>& Q, unordered_set<string>& acSource, unordered_set<string>& acDest) {
    int size = Q.size();
    while (size--) {
        string cur = Q.front();
        Q.pop();
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                string ins = cur.substr(i, j-i+1);
                string rest = cur.substr(0, i) + cur.substr(j+1, n-j);
                for (int k = 0; k < n-(j-i+1); k++) {
                    string left = rest.substr(0, k);
                    string right = rest.substr(k, n-k);
                    string s = left + ins + right;
                    if (s != cur) {
                        if (acDest.count(s))
                            return true;
                        Q.push(s);
                        acSource.insert(s);
                    }
                }
            }
        }
    }
    return false;
}

int main() {
    int test = 1;
    while (scanf("%d", &n), n) {
        string source, tmp, dest;
        for (int i = 0; i < n; i++) {
            cin >> tmp;
            source += tmp;
            dest += ('1' + i);
        }
        if (source == dest) {
            printf("Case %d: %d\n", test++, 0);
            continue;
        }
        unordered_set<string> acSource;
        unordered_set<string> acDest;
        acSource.insert(source);
        acDest.insert(dest);
        queue<string> Q;
        Q.push(source);
        int count = 0;
        /* Max 5 level, start from source and dest */
        bool found = false;
        for (int i = 0; i < 2; i++) {
            if (found)
                break;
            found = find(Q, acSource, acDest);
            count++;
        }
        while (!Q.empty())
            Q.pop();
        Q.push(dest);
        for (int i = 0; i < 2; i++) {
            if (found)
                break;
            found = find(Q, acDest, acSource);
            count++;
        }
        if (!found)
            count = 5;
        printf("Case %d: %d\n", test++, count);
    }
}