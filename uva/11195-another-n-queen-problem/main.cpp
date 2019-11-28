#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
using namespace std;

int ans, OK;
int n;
int block[15];

void backtrack(int rw, int ld, int rd, int level) {
    if (rw == OK) {
        ans++;
        return;
    }
    int pos = OK & (~(rw | ld | rd | block[level]));
    while (pos) {
        int p = pos & -pos;
        pos -= p;
        backtrack(rw | p, (ld | p) >> 1, (rd | p) << 1, level + 1);
    }
}

int main() {
    int test = 1;
    int row, col;
    while (scanf("%d", &n), n) {
        memset(block, 0, sizeof(block));
        OK = (1 << n) - 1;
        ans = 0;
        string tmp;
        for (int i = 0; i < n; i++) {
            cin >> tmp;
            int b = 0;
            for (int j = 0; j < n; j++) {
                b <<= 1;
                if (tmp[j] == '*')
                    b |= 1;
            }
            block[i] = b;
        }
        backtrack(0, 0, 0, 0);
        printf("Case %d: %d\n", test++, ans);
    }
    return 0;
}
