#include <bits/stdc++.h>
using namespace std;

int main() {
    unordered_map<char, bool> m;
    int n;
    scanf("%d\n", &n);
    vector<bool> v(n, false);
    char tmp;
    for (size_t i = 0; i < n; i++) {
        cin >> tmp;
        if (tmp == 'T') {
            v[i] = true;
        }
    }
    stack<bool> s;
    int index = 0;
    while (scanf(" %c ", &tmp) != EOF) {
        if (tmp >= 'A' && tmp <= 'Z') {
            if (!m.count(tmp)) {
                m[tmp] = v[index++];
            }
            bool cur = m[tmp];
            s.push(cur);
        } else {
            bool first, second;
            if (tmp == '-') {
                second = s.top();
                s.pop();
                second = !second;
                s.push(second);
            } else if (tmp == '+') {
                first = s.top();
                s.pop();
                second = s.top();
                s.pop();
                second = first | second;
                s.push(second);
            } else {
                first = s.top();
                s.pop();
                second = s.top();
                s.pop();
                second = first & second;
                s.push(second);
            }
        }
    }
    if (s.top() == true) {
        printf("T\n");
    } else {
        printf("F\n");
    }
    return 0;
}
