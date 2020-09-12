#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

int main() {
    int n, q;
    while (cin >> n >> q) {
	    unordered_map<int, vector<int>> m;
	    int tmp;
	    for (int i = 1; i <= n; i++) {
	    	cin >> tmp;
	    	m[tmp].push_back(i);
	    }
	    int index, num;
	    while (q--) {
	    	cin >> index >> num;
	    	if (m[num].size() < index)
	    		cout << 0 << endl;
	    	else
	    		cout << m[num][index-1] << endl;
	    }
    }
    return 0;
}