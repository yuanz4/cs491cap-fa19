#include <cstdio>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_set>
using namespace std;

typedef vector<int> vi;

int main() {
	int n;
	scanf("%d", &n);
	int a[n];
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	unordered_set<int> visited;
	unordered_set<int> in;
	vi day;
	int count = 0;
	for (int i = 0; i < n; i++) {
		if (a[i] > 0) {
			if (!visited.count(a[i])) {
				visited.insert(a[i]);
				in.insert(a[i]);
				count++;
			} else {
				if (in.count(a[i])) {
					cout << -1 << endl;
					return 0;
				} else {
					if (!in.empty()) {
						cout << -1 << endl;
						return 0;
					} else {
						visited.insert(a[i]);
						in.insert(a[i]);
						count++;
					}
				}
			}
		} else {
			int t = -a[i];
			if (!visited.count(t)) {
				cout << -1 << endl;
				return 0;
			} else {
				if (!in.count(t)) {
					cout << -1 << endl;
					return 0;
				} else {
					in.erase(t);
					count++;
					if (in.empty()) {
						day.push_back(count);
						count = 0;
						visited.clear();
						in.clear();
					}
				}
			}
		}
	}
	if (!in.empty()) {
		cout << -1 << endl;
		return 0;
	} else {
		if (count)
			day.push_back(count);
	}
	cout << day.size() << endl;
	for (int i = 0; i < day.size(); i++) {
		if (i == day.size()-1)
			cout << day[i] << endl;
		else
			cout << day[i] << ' ';
	}
	return 0;
}