#include <bits/stdc++.h>

using namespace std;

#define lft at<<1
#define ryt at<<1|1
enum {CLR = 0, ZERO, ONE, FLIP};
const int MX = 1024000 + 7;
int A[MX], T[MX<<2] , lazy[MX<<2];

void build(int at , int l, int r) {
    lazy[at] = CLR;
    if(l == r) {
        T[at] = A[l];
        return;
    }
    int mid = (l+r) >> 1;
    build(lft, l, mid);
    build(ryt, mid+1, r);
    T[at] = T[lft] + T[ryt];
}

int doFlip(int x) {
    if(x == ONE)
    	return ZERO;
    if(x == ZERO)
    	return ONE;
    if(x == FLIP)
    	return CLR;
    return FLIP ;
}

void propagate(int at, int l, int r) {
    if (lazy[at] == CLR)
    	return;
    if (lazy[at] == ZERO)
        T[at] = 0;
    else if (lazy[at] == ONE)
        T[at] = r - l + 1;
    else if (lazy[at] == FLIP)
        T[at] = (r - l + 1) - T[at];
    if(l != r) {
        if(lazy[at] == ZERO || lazy[at] == ONE)
            lazy[lft] = lazy[ryt] = lazy[at];
        else {
            lazy[lft] = doFlip(lazy[lft]);
            lazy[ryt] = doFlip(lazy[ryt]);
        }
    }
    lazy[at] = CLR;
}

int query(int at, int l, int r, int x, int y) {
	propagate(at, l, r);
    if(x > r || y < l)
    	return 0;
    if(x <= l && y >= r)
    	return T[at];
    int mid = (l+r) >> 1;
    int q1 = query(lft, l, mid, x, y);
    int q2 = query(ryt, mid+1, r, x, y);
    return q1 + q2;
}

void update(int at, int l, int r, int x, int y, int type) {
	propagate(at, l, r);
    if(x > r || y < l)
    	return;
    if(x <= l && y >= r) {
    	if (type == ZERO) {
    		T[at] = 0;
        	lazy[lft] = lazy[ryt] = ZERO;
    	} else if (type == ONE) {
    		T[at] = r - l + 1;
	        lazy[lft] = lazy[ryt] = ONE;
    	} else if (type == FLIP) {
    		T[at] = (r - l + 1) - T[at];
	        lazy[lft] = doFlip(lazy[lft]);
	        lazy[ryt] = doFlip(lazy[ryt]);
    	}
    	return;
    }
    int mid = (l+r) >> 1;
    update(lft, l, mid, x, y, type);
    update(ryt, mid+1, r, x, y, type);
    T[at] = T[lft] + T[ryt];
}

int main() {
	int test;
	scanf("%d", &test);
	int test_index = 1;
	while (test--) {
		int M;
		scanf("%d", &M);
		printf("Case %d:\n", test_index++);
		char str[60];
		int N = 0;
		while (M--) {
			int T;
			scanf("%d", &T);
			scanf("%s", str);
			while (T--) {
				for (int i = 0; i < strlen(str); i++)
					A[N++] = str[i] - '0';
			}
		}
		build(1, 0, N-1);
		scanf("%d", &M);
		char Q;
		int x, y;
		int q = 0;
		while (M--) {
			scanf(" %c %d %d", &Q, &x, &y);
			if (Q == 'F')
				update(1, 0, N-1, x, y, ONE);
			else if (Q == 'E')
				update(1, 0, N-1, x, y, ZERO);
			else if (Q == 'I')
				update(1, 0, N-1, x, y, FLIP);
			else
				printf("Q%d: %d\n", ++q, query(1, 0, N-1, x, y));
		}
	}
	return 0;
}