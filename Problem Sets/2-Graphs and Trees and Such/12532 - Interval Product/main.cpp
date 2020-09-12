#include <bits/stdc++.h>

using namespace std;

const int MX = 100000+7;
int v[MX], ft[MX], fto[MX];

void build(int N) {
	int start = 1;
	int interval = 1;
	while (start <= N) {
		for (int i = start; i <= N; i += interval*2) {
			for (int j = i; j > i-interval; j--) {
				if (!v[j])
					fto[i]++;
				else
					ft[i] *= v[j];
			}
		}
		start <<= 1;
		interval <<= 1;
	}
}

pair<int, int> search(int n) {
	pair<int, int> ret = {1, 0};
	while (n) {
		ret.first *= ft[n];
		ret.second += fto[n];
		int lsOne = n & -n;
		n -= lsOne;
	}
	return ret;
}

void query(int i, int j) {
	pair<int, int> first = search(i-1);
	pair<int, int> second = search(j);
	int zero = second.second - first.second;
	if (zero > 0)
		printf("0");
	else if (second.first/first.first == 1)
		printf("+");
	else
		printf("-");
}

void update(int i, int j, int N) {
	if (j > 0)
		j = 1;
	else if (j < 0)
		j = -1;
	if (v[i] == j)
		return;
	int lsOne, origin = v[i];
	v[i] = j;
	if (origin == -1 || origin == 1) {
		while (i <= N) {
			if (j)
				ft[i] *= -1;
			else {
				ft[i] /= origin;
				fto[i]++;
			}
			lsOne = i & -i;
			i += lsOne;
		}
	} else {
		while (i <= N) {
			ft[i] *= j;
			fto[i]--;
			lsOne = i & -i;
			i += lsOne;
		}
	}
}

int main() {
	int N, K;
	while (~scanf("%d %d", &N, &K)) {
		int tmp;
		for (int i = 1; i <= N; i++) {
			scanf("%d", &tmp);
			if (tmp == 0)
				v[i] = 0;
			else if (tmp > 0)
				v[i] = 1;
			else
				v[i] = -1;
			ft[i] = 1;
			fto[i] = 0;
		}
		char q;
		int i, j;
		build(N);
		while (K--) {
			scanf(" %c %d %d", &q, &i, &j);
			if (q == 'C')
				update(i, j, N);
			else
				query(i, j);
		}
		printf("\n");
	}
	return 0;
}