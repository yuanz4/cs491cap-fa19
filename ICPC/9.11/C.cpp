#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
 
using namespace std;
 
int main()
{
	int total;
	cin >> total;
	vector<int> v(total, 0);
	for (int i = 0; i < total; i++)
		cin >> v[i];
	int q;
	cin >> q;
	int thresh = -1;
	unordered_set<int> s;
	while (q--) {
		int op;
		cin >> op;
		if (op == 1) {
			int i, eq;
			cin >> i >> eq;
			v[i-1] = eq;
			if (eq <= thresh)
				s.insert(i-1);
		} else {
			int eq;
			cin >> eq;
			if (eq > thresh) {
				thresh = eq;
				s.clear();
			} else if (eq < thresh) {
				for (int i: s)
					v[i] = max(v[i], eq);
			}
		}
	}
	for (int i = 0; i < total; i++) {
		if (s.count(i) || v[i]>thresh)
			cout << v[i];
		else
			cout << thresh;
		if (i != total-1)
			cout << " ";
	}
	cout << endl;
	return 0;
}

// #include <iostream>
// #include <vector>
// #include <algorithm>
// #include <map>
// #include <unordered_set>

// using namespace std;

// int main()
// {
// 	int total;
// 	cin >> total;
// 	vector<int> v(total, 0);
// 	for (int i = 0; i < total; i++)
// 		cin >> v[i];
// 	int q;
// 	cin >> q;
// 	int thresh = -1;
// 	unordered_set<int> s;
// 	map<int, vector<int>> m;
// 	while (q--) {
// 		int op;
// 		cin >> op;
// 		if (op == 1) {
// 			int i, eq;
// 			cin >> i >> eq;
// 			if (s.count(i-1)) {
// 				int j = 0;
// 				for (; j < m[v[i-1]].size(); j++)
// 					if (m[v[i-1]][j] == i-1)
// 						break;
// 				m[v[i-1]].erase(m[v[i-1]].begin()+j);
// 			}
// 			v[i-1] = eq;
// 			s.insert(i-1);
// 			m[eq].push_back(i-1);
// 		} else {
// 			int eq;
// 			cin >> eq;
// 			if (eq > thresh) {
// 				thresh = eq;
// 				s.clear();
// 				m.clear();
// 			} else if (eq < thresh) {
// 				while (true) {
// 					if (m.begin()->first < eq) {
// 						vector<int> cur = m.begin()->second;
// 						m[eq].insert(m[eq].begin(), cur.begin(), cur.end());
// 						m.erase(m.begin());
// 					} else
// 						break;
// 				}
// 			}
// 		}
// 	}
// 	for (auto it: m) {
// 		for (int i: it.second)
// 			v[i] = it.first;
// 	}
// 	for (int i = 0; i < total; i++) {
// 		if (s.count(i) || v[i]>thresh)
// 			cout << v[i];
// 		else
// 			cout << thresh;
// 		if (i != total-1)
// 			cout << " ";
// 	}
// 	cout << endl;
// 	return 0;
// }