#include <iostream>
#include <algorithm>
#include <map>
#include <string>

using namespace std;

void output(int L, int R) {
    if (L == -1)
    	cout << '*';
    else
    	cout << to_string(L);
    cout << ' ';
    if (R == -1)
    	cout << '*';
    else
    	cout << to_string(R);
    cout << endl;
}

int main() {
    int S, B;
    while (cin>>S>>B) {
        if (!S && !B)
        	break;
        map<int, int> m;
        m[1] = S;
        for (int i = 0; i < B; i++) {
        	int left, right;
        	cin >> left >> right;
        	// cout << "------------------------------" << endl;
        	// cout << "map = ";
        	// for (auto it = m.begin(); it != m.end(); it++) {
        	// 	cout << it->first << " " << it->second << ", ";
        	// }
        	// cout << endl;
        	auto it = m.lower_bound(left);
        	if (it==m.end() || it->first!=left)
        		it--;
        	int L = -1, R = -1;
        	if (it->first==left && it->second==right) {
        		// delete block
    			if (it != m.begin()) {
    				L = (--it)->second;
    				it++;
    			}
    			if (++it != m.end())
    				R = it->first;
    			it--;
    			m.erase(it);
    		} else if (it->first!=left && it->second!=right) {
    			// insert another block
    			L = left-1;
    			R = right+1;
    			m[R] = it->second;
    			it->second = L;
    		} else if (it->first==left && it->second!=right) {
    			// shorten from left
    			if (it != m.begin()) {
    				L = (--it)->second;
    				it++;
    			}
    			R = right+1;
    			// cannot change key directly
    			m[R] = it->second;
    			m.erase(it);
    		} else {
    			// shorten from right
    			L = left-1;
    			if (++it != m.end())
    				R = it->first;
    			it--;
    			it->second = L;
    		}
        	output(L, R);
        }
        cout << '-' << endl;
    }
    return 0;
}
