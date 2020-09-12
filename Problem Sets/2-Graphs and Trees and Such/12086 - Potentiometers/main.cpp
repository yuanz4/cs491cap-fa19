#include <bits/stdc++.h>

using namespace std;

const int MX = 200000+7;
int v[MX], ft[MX];

void build(int N) {
    int start = 1;
    int interval = 1;
    while (start <= N) {
        for (int i = start; i <= N; i += interval*2) {
            for (int j = i; j > i-interval; j--) {
                ft[i] += v[j];
            }
        }
        start <<= 1;
        interval <<= 1;
    }
}

int search(int n) {
    int ret = 0;
    int lsOne;
    while (n) {
        ret += ft[n];
        lsOne = n & -n;
        n -= lsOne;
    }
    return ret;
}

void query(int i, int j) {
    int first = search(i-1);
    int second = search(j);
    printf("%d\n", second-first);
}

void update(int i, int j, int N) {
    if (v[i] == j)
        return;
    int lsOne;
    int diff = j-v[i];
    v[i] = j;
    while (i <= N) {
        ft[i] += diff;
        lsOne = i & -i;
        i += lsOne;
    }
}

int main() {
    int N;
    int index = 1;
    while (scanf("%d", &N), N) {
        for (int i = 1; i <= N; i++) {
            scanf("%d", &v[i]);
            ft[i] = 0;
        }
        build(N);
        if (index > 1)
            printf("\n");
        printf("Case %d:\n", index++);
        char str[20];
        int i, j;
        while (scanf("%s", str)) {
            if (strcmp(str, "END") == 0)
                break;
            scanf("%d %d", &i, &j);
            if (strcmp(str, "M") == 0)
                query(i, j);
            else
                update(i, j, N);
        }
    }
    return 0;
}