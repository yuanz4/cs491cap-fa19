#include <iostream>
#include <set>
#include <vector>

using namespace std;

int main() {
    int total;
    cin >> total;
    for (int i = 0; i < total; i++) {
    	int B, SG, SB;
    	cin >> B >> SG >> SB;
    	multiset<int, greater<int>> g;
    	multiset<int, greater<int>> b;
    	int tmp;
    	for (int j = 0; j < SG; j++) {
    		cin >> tmp;
    		g.insert(tmp);
    	}
    	for (int j = 0; j < SB; j++) {
    		cin >> tmp;
    		b.insert(tmp);
    	}
    	while (g.size() && b.size()) {
    		auto gi = g.begin();
    		auto bi = b.begin();
    		vector<int> gs, bs;
    		for (int j = 0; j < B; j++) {
    			if (gi!=g.end() && bi!=b.end()) {
    				if (*gi > *bi)
    					gs.push_back(*gi-*bi);
    				else if (*gi < *bi)
    					bs.push_back(*bi-*gi);
    				gi++;
    				bi++;
    			} else
    				break;
    		}
			g.erase(g.begin(), gi);
			b.erase(b.begin(), bi);
			g.insert(gs.begin(), gs.end());
			b.insert(bs.begin(), bs.end());
    	}
    	if (g.empty() && b.empty())
    		cout << "green and blue died" << endl;
    	else if (g.empty()) {
    		cout << "blue wins" << endl;
    		for (int j: b)
    			cout << j << endl;
    	} else {
    		cout << "green wins" << endl;
    		for (int j: g)
    			cout << j << endl;
    	}
    	if (i != total-1)
	    	cout << endl;
    }
    return 0;
}
