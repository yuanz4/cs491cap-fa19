#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int total, k;
	cin >> total >> k;
	vector<int> v(total, 0);
	for (int i = 0; i < total; i++)
		cin >> v[i];
	int i = 0;
	while (i < v.size()) {
		if (v[i] <= k)
			i++;
		else
			break;
	}
	int j = v.size()-1;
	while (j>=0 && j>i) {
		if (v[j] <= k)
			j--;
		else
			break;
	}
	cout << i+v.size()-1-j << endl;
	return 0;
}