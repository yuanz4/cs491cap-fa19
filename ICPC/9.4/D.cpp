#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int lengthOfLIS(vector<int>& nums) {
    vector<int> ret;
    for (int i: nums) {
        if (ret.empty() || i>ret.back())
            ret.push_back(i);
        else {
            auto it = lower_bound(ret.begin(), ret.end(), i);
            *it = i;
        }
    }
    return ret.size();
}

int main()
{
	int size;
	cin >> size;
	vector<int> v(size, 0);
	for (int i = 0; i < size; i++)
		cin >> v[i];
	int ret = lengthOfLIS(v);
	for (int i = 0; i < size; i++) {
		for (int j = i+2; j <= size; j++) {
			reverse(v.begin()+i, v.begin()+j);
			int cur = lengthOfLIS(v);
			ret = max(ret, cur);
			reverse(v.begin()+i, v.begin()+j);
		}
	}
	cout << ret << endl;
	return 0;
}