#include <cstdio>
#include <cstring>
#include <string>
#include <iostream>
using namespace std;

int n, maxd;
string a;

int h() {
    int cnt = 0;
    for(int i = 0; i < n-1; i++)
        if(a[i]+1 != a[i+1])
            cnt++;
    if(a[n-1] != (n+'0'))
        cnt++;
    return cnt;
}

bool dfs(int d) {
    // printf("%d %d %s %d\n", maxd, d, a.c_str(), h());
    int cnt = h();
    if(d*3 + cnt > maxd*3)
        return false;
    if (!cnt)
        return true;
    string b = a;
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            string ins = b.substr(i, j-i+1);
            string rest = b.substr(0, i) + b.substr(j+1, n-j);
            for (int k = 0; k < n-(j-i+1); k++) {
                string left = rest.substr(0, k);
                string right = rest.substr(k, n-k);
                string s = left + ins + right;
                if (s != b) {
                    a = s;
                    if (dfs(d+1))
                        return true;
                }
            }
        }
    }
    a = b;
    return false;
}

int main(){
    int test = 1;
    while (scanf("%d", &n), n) {
        string tmp;
        a.clear();
        for (int i = 0; i < n; i++) {
            cin >> tmp;
            a += tmp;
        }
        for (maxd = 0; ; maxd++)
            if (dfs(0))
                break;
        printf("Case %d: %d\n", test++, maxd);
    }
    return 0;
}