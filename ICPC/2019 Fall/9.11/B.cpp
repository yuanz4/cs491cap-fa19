#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int total;
	cin >> total;
	vector<int> v(total, 0);
	for (int i = 0; i < total; i++)
		cin >> v[i];
	bool increase = true;
	for (int i = 0; i < total-1; i++) {
		if (increase) {
			if (v[i+1] < v[i])
				increase = false;
		} else {
			if (v[i+1] > v[i]) {
				cout << "NO" << endl;
				return 0;
			}
		}
	}
	cout << "YES" << endl;
	return 0;
}