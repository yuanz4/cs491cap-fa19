#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstring>
#include <stack>
using namespace std;

int main() {
	int first = 0;
	char a[90] = "#";
	char b[90] = "#";
	while (gets(a+1)) {
		if (first++)
			printf("\n");
		gets(b+1);
		int m = strlen(a)-1, n = strlen(b)-1;
        int d[m+1][n+1];
        int p[m+1][n+1];
        memset(p, -1, sizeof(p));
        for (int i = 0; i <= m; i++)
            d[i][0] = i;
        for (int j = 0; j <= n; j++)
            d[0][j] = j;
        // left: 0, up, 1, left up dif: 2, left up same: 3
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (a[i] == b[j]) {
                    d[i][j] = d[i-1][j-1];
                    p[i][j] = 3;
                } else {
                	int prev[3] = {d[i][j-1], d[i-1][j], d[i-1][j-1]};
                	int* mini = min_element(prev, prev+3);
                    d[i][j] = *mini + 1;
                    p[i][j] = mini - prev;
                }
            }
        }
        printf("%d\n", d[m][n]);
        int i = m, j = n;
        int command = 1;
        while (i != 0 || j != 0) {
        	if (i*j == 0) {
        		while (i > 0) {
        			printf("%d Delete %d\n", command++, i);
            		i--;
        		}
        		while (j > 0) {
        			printf("%d Insert %d,%c\n", command++, i+1, b[j]);
            		j--;
        		}
        		break;
        	}
        	if (p[i][j] == 0) {
	    		printf("%d Insert %d,%c\n", command++, i+1, b[j]);
	    		j--;
    		} else if (p[i][j] == 1) {
    			printf("%d Delete %d\n", command++, i);
    			i--;
    		} else {
    			if (p[i][j] == 2)
	    			printf("%d Replace %d,%c\n", command++, i, b[j]);
	    		i--;
    			j--;
    		}
        }
	}
	return 0;
}