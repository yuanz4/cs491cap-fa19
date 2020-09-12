#include <iostream>
#include <stack>

using namespace std;

int main() {
    int total;
    bool null = false;
    while (cin >> total) {
        if (!total)
            break;
        int a[total];
        for (int i = 0; i < total; i++)
            a[i] = i+1;
        while (true) {
            int b[total];
            cin >> b[0];
            if (!b[0]) {
                cout << endl;
                break;
            }
            for (int j = 1; j < total; j++)
                cin >> b[j];
            int i = 0, j = 0;
            stack<int> s;
            bool good = true;
            while (j < total) {
                if (i == total) {
                    if (!s.empty() && s.top()==b[j]) {
                        j++;
                        s.pop();
                    } else {
                        good = false;
                        break;
                    }
                } else {
                    if (a[i] == b[j]) {
                        i++;
                        j++;
                    } else if (!s.empty() && s.top()==b[j]) {
                        j++;
                        s.pop();
                    } else {
                        s.push(a[i++]);
                    }
                }
            }
            if (good)
                cout << "Yes" << endl;
            else
                cout << "No" << endl;
        }
    }
    return 0;
}