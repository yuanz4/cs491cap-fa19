#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
	int total;
	cin >> total;
	while (total--) {
		int size;
		string s;
		cin >> size >> s;
		int low = 0, high = size-1;
		while (low < high) {
			int a = s[low++]-'a';
			int b = s[high--]-'a';
			if (a==b || abs(a-b)==2)
				continue;
			cout << "NO" << endl;
			goto next;
		}
		cout << "YES" << endl;
		next:;
	}
	return 0;
}