#include <cstdio>
#include <iostream>
#include <vector>
#include <string>
using namespace std;

typedef vector<int> vi;

int main() {
	int t;
	scanf("%d", &t);
	int A[100007], B[100007];
	while (t--) {
		int n;
		scanf("%d", &n);
		for (int i = 0; i < n; i++)
			scanf("%d", &A[i]);
		for (int i = 0; i < n; i++) {
			scanf("%d", &B[i]);
			B[i] -= A[i];
		}
		int forward = 0;
		int backward = n-1;
		int ss;
		for (int i = 0; i < n; i++) {
			if (B[i] < 0) {
				cout << "NO" << endl;
				goto next;
			} else if (B[i] > 0) {
				forward = i;
				break;
			}
		}
		for (int i = n-1; i >= 0; i--) {
			if (B[i] < 0) {
				cout << "NO" << endl;
				goto next;
			} else if (B[i] > 0) {
				backward = i;
				break;
			}
		}
		ss = B[forward];
		for (int i = forward; i <= backward; i++) {
			if (B[i] != ss) {
				cout << "NO" << endl;
				goto next;
			}
		}
		cout << "YES" << endl;
		next:;
	}
	return 0;
}