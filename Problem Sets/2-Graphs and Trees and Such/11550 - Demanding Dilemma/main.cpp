#include <bits/stdc++.h>

using namespace std;

int main() {
    int test;
    scanf("%d", &test);
    while (test--) {
        int n, m;
        scanf("%d %d", &n, &m);
        int matrix[n][m];
        bool vertex[n][n];
        memset(vertex, 0, sizeof vertex);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                scanf("%d", &matrix[i][j]);
            }
        }
        for (int j = 0; j < m; j++) {
            int first = -1, second = -1;
            for (int i = 0; i < n; i++) {
                if (matrix[i][j]) {
                    if (first == -1)
                        first = i;
                    else if (second == -1)
                        second = i;
                    else {
                        printf("No\n");
                        goto finish;
                    }
                }
            }
            if (first == -1 || second == -1) {
                printf("No\n");
                goto finish;
            }
            if (vertex[first][second]) {
                printf("No\n");
                goto finish;
            }
            vertex[first][second] = 1;
        }
        printf("Yes\n");
        finish:;
    }
    return 0;
}