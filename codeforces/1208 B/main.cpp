#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_set>

using namespace std;

int main() {
    int n;
    int tmp;
    while (cin >> n) {
    	vector<int> v;
        for (int i = 0; i < n; i++) {
        	cin >> tmp;
        	v.push_back(tmp);
        }
        unordered_set<int> s;
        int left = 0, right = n-1;
        int ret = 0;
        while (!s.count(v[left]) && left<n)
    		s.insert(v[left++]);
		ret = left;
		left--;
        while (true) {
        	while (!s.count(v[right]) && right>left)
        		s.insert(v[right--]);
        	ret = max(ret, left+n-right);
            if (left < 0)
                break;
        	int dup = v[right];
        	while (left >= 0) {
        		if (v[left] != dup)
        			s.erase(v[left--]);
        		else {
        			s.erase(v[left--]);
        			break;
        		}
        	}
        }
        cout << n-ret << endl;
    }
    return 0;
}
