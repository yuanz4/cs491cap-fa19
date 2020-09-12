#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int main() {
    string s;
    int index = 1;
    while (cin >> s) {
        if (s == "end")
            break;
        vector<stack<int>> v;
        for (char c: s) {
            int cur = c-'A';
            int big = INT_MAX, argbig = -1;
            for (int i = 0; i < v.size(); i++) {
                if (v[i].top() >= cur) {
                    if (v[i].top() < big) {
                        big = v[i].top();
                        argbig = i;
                    }
                }
            }
            if (argbig == -1) {
                stack<int> tmp;
                tmp.push(cur);
                v.push_back(tmp);
            } else
                v[argbig].push(cur);
        }
        cout << "Case " << index++ << ": " << v.size() << endl;
    }
    return 0;
}