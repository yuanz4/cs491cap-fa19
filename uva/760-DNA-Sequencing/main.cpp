#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <cstring>
#include <algorithm>
#include <set>
using namespace std;

const int MX = 2*300 + 7;
char T[MX];
int SA[MX], LCP[MX], Owner[MX];
int n;

bool cmp(int a, int b) {
	return strcmp(T + a, T + b) < 0;
}

int main() {
    string a, b;
    int first = 0;
    while (cin >> a) {
    	if (first++)
    		printf("\n");
        cin >> b;
        int nA = a.size()+1;
        string concat = a + "$" + b + "#";
        strcpy(T, concat.c_str());
        n = strlen(T);
		for (int i = 0; i < n; i++)
			SA[i] = i;
		sort(SA, SA + n, cmp);
		for (int i = 0; i < n; i++)
			Owner[i] = SA[i] < nA ? 1 : 2;
		set<string> s;
		LCP[0] = 0;
		int sol = 0;
		for (int i = 1; i < n; i++) {
			int L = 0;
			while (T[SA[i] + L] == T[SA[i-1] + L])
				L++;
			LCP[i] = L;
			if (L && Owner[i] != Owner[i-1]) {
				string cur(T, SA[i], L);
				if (L > sol) {
					sol = L;
					s.clear();
					s.insert(cur);
				} else if (L == sol)
					s.insert(cur);
			}
		}
		// for (int i = 0; i < n; i++)
		// 	printf("%d\t%d\t%d\t%s\n", SA[i], LCP[i], Owner[i], T + SA[i]);
		if (!sol)
			printf("No common sequence.\n");
		else {
			for (string tmp: s)
				cout << tmp << endl;
		}
    }
    return 0;
}