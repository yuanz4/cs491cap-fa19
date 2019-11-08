#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

int main() {
    int P, D;
    scanf("%d %d\n", &P, &D);
    vector<pair<int, int>> v(D+1, pair<int, int>(0, 0));
    int d, a, b;
    ld total = 0;
    for (size_t i = 0; i < P; i++) {
        scanf("%d %d %d\n", &d, &a, &b);
        v[d].first += a;
        v[d].second += b;
        total += a + b;
     }
     ll A = 0, B = 0;
     for (size_t i = 1; i <= D; i++) {
         int win = 0;
         int first = v[i].first, second = v[i].second;
         if (first > second) {
             win = 0;
             a = first - ((first+second)/2+1);
             b = second;
         } else {
             win = 1;
             a = first;
             b = second - ((first+second)/2+1);
         }
         A += a;
         B += b;
         printf("%c %d %d\n", win+'A', a, b);
     }
     ld rate = labs(A-B) / total;
     printf("%Lf\n", rate);
    return 0;
}
