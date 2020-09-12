#include <cstdio>
#include <bitset>
using namespace std;

typedef long long ll;
const ll _sieve_size = 1e6+7;
bitset<_sieve_size> bs;

void sieve() {
    bs.set(); // all bits set to 1
    bs[0] = bs[1] = 0;
    for (ll i = 2; i <= _sieve_size; i++)
    if (bs[i]) { // cross out multiples of i starting from i * i!
        for (ll j = i * i; j <= _sieve_size; j += i)
            bs[j] = 0;
    }
}

int main() {
    sieve();
    int n;
    while (scanf("%d", &n), n) {
        int a = 3, b = -1; // skip 2, even
        for (; a <= n/2; a += 2) {
            if (!bs[a])
                continue;
            if (bs[n-a]) {
                b = n - a;
                break;
            }
        }
        if (b == -1)
            printf("Goldbach's conjecture is wrong.\n");
        else
            printf("%d = %d + %d\n", n, a, b);
    }
    return 0;
}