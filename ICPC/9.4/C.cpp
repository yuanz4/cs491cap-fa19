#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int size, op;
	cin >> size >> op;
	vector<int> v(size, 0);
	for (int i = 0; i < size; i++)
		cin >> v[i];
	sort(v.begin(), v.end());
	int mid = (size-1)/2;
	for (int i = mid; i < size-1; i++) {
		while (v[i+1] > v[i]) {
			for (int j = i; j >= mid; j--) {
				if (!op)
					goto finish;
				v[j]++;
				op--;
			}
		}
	}
	if (op)
		v[mid] += op/((size+1)/2);
	finish:
	cout << v[mid] << endl;
	return 0;
}