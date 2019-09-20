#include <iostream>
#include <string>

using namespace std;

int main() {
	int test;
	cin >> test;
	while (test--) {
		int M;
		cin >> M;
		string P;
		while (M--) {
			int T;
			cin >> T;
			string s;
			cin >> s;
			while (T--) {
				P += s;
			}
		}
		int N = P.size();
		cin >> M;
		char Q;
		int a, b;
		while (M--) {
			cin >> Q >> a >> b;
		}
		cout << P << endl;
	}
	return 0;
}