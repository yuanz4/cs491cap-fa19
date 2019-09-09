#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main() {
    string text;
    while (cin>>text) {
        stack<string> s;
        string cur;
        text += ']';
        for (char c: text) {
            if (c == '[') {
                s.push(cur);
                cur = "";
            } else if (c == ']') {
                while (!s.empty()) {
                    cur += s.top();
                    s.pop();
                }
            } else
                cur += c;
        }
        cout << cur << endl;
    }
    return 0;
}
