#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MX = 100000+7;
char d[MX];
int n;

int main() {
    scanf("%s\n", d);
    n = strlen(d);
    ll ret = 0;
    int index = 1;
    for (size_t i = 1; i < n; i++) {
        if (d[i] == d[i-1]) {
            continue;
        } else {
            d[index++] = d[i];
        }
    }
    d[index] = '\0';
    // printf("%d %s\n", index, d);
    int count[26];
    for (size_t i = 2; i <= index; i++) {
        memset(count, 0, sizeof count);
        for (size_t j = 0; j < i-1; j++) {
            count[d[j]-'a']++;
        }
        for (size_t j = i-1; j < index; j++) {
            count[d[j]-'a']++;
            if (d[j] != d[j-i+1] && count[d[j]-'a'] == 1 && count[d[j-i+1]-'a'] == 1) {
                ret++;
            }
            count[d[j-i+1]-'a']--;
        }
    }
    printf("%lld\n", ret);
}
