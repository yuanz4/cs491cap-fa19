#include <cstdio>
#include <vector>
#include <string>
#include <iostream>
using namespace std;

int main() {
	string s;
	cin >> s;
	vector<int> w, o;
	int n = s.size();
	string pro;
	for (int i = 0; i < n-1; i++) {
		if (s[i] == 'o')
			pro += 'o';
		else if (s[i] == 'v' && s[i+1] == 'v')
			pro += 'v';
	}
	// cout << pro << endl;
	bool v = true;
	int cons = 0;
	for (int i = 0; i < pro.size(); i++) {
		if (v) {
			if (pro[i] == 'v')
				cons++;
			else {
				if (w.empty() && cons == 0)
					continue;
				w.push_back(cons);
				v = false;
				cons = 1;
			}
		} else {
			if (pro[i] == 'o')
				cons++;
			else {
				o.push_back(cons);
				v = true;
				cons = 1;
			}
		}
	}
	if (v)
		w.push_back(cons);
	else
		o.push_back(cons);
	int wn = w.size();
	// printf("%d\n", wn);
	vector<int> acc(wn, 0);
	for (int i = 1; i < wn; i++)
		acc[i] = o[i-1] + acc[i-1];
	// for (int i = 0; i < acc.size(); i++)
	// 	printf("%d\n", acc[i]);
	long long ret = 0;
	for (int i = 0; i < wn; i++) {
		for (int j = i+1; j < wn; j++) {
			ret += w[i] * w[j] * (acc[j]-acc[i]);
		}
	}
	// if (w.size() == o.size())
	// 	o.pop_back();
	// for (int i = 0; i < o.size(); i++) {
	// 	printf("%d %d ", w[i], o[i]);
	// }
	// printf("%d\n", w.back());
	cout << ret << endl;
	return 0;
}