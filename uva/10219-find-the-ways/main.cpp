#include <cstdio>
#include <cmath>
 
double digit(int n) {
    return (0.5*log(2.0*acos(-1.0)*n) + n*log(n+0.0) - n)/log(10.0);
}
 
int main() {
    int n, k;
    while (~scanf("%d%d", &n, &k))
        printf("%d\n",int(digit(n)-digit(k)-digit(n-k))+1);
    
    return 0;
}