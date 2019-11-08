#include <bits/stdc++.h>

using namespace std;

bool factorize(int N, unordered_map<int, int>& result) {
    vector<bool> t(N+1, true);
    t[0] = false;
    t[1] = false;
    for (int i = 2; i*i <= N; i++) {
        if (t[i]) {
            for (int j = i*i; j <= N; j += i)
                t[j] = false;
        }
    }
    vector<int> prime;
    for (int i = 0; i <= N; i++) {
        if (t[i])
            prime.push_back(i);
    }
    int p = 0;
    while (N != 1) {
        if (N%prime[p] == 0) {
            result[prime[p]]++;
            N /= prime[p];
        } else {
            p++;
        }
        if (result.size() > 2) {
            return true;
        }
    }
    return false;
}

int main() {
    int n;
    cin >> n;
    while (n--) {
        int N;
        string name;
        cin >> N >> name;
        unordered_map<int, int> result;
        bool tie = factorize(N, result);
        if (tie) {
            cout << "tie" << endl;
            continue;
        }
        bool another;
        auto it = result.begin();
        int c1 = it->second;
        if (result.size() == 1) {
            if (c1 == 1) {
                another = false;
            } else {
                cout << "tie" << endl;
                continue;
            }
        } else {
            it++;
            int c2 = it->second;
            int diff = abs(c1-c2);
            if (diff == 0) {
                another = true;
            } else if (diff == 1) {
                another = false;
            } else if (diff > 1) {
                cout << "tie" << endl;
                continue;
            }
        }
        if (another) {
            if (name == "Alice") {
                cout << "Bob" << endl;
            } else {
                cout << "Alice" << endl;
            }
        } else {
            if (name == "Alice") {
                cout << "Alice" << endl;
            } else {
                cout << "Bob" << endl;
            }
        }
    }
    return 0;
}

// 10
// 10 Alice
// 20 Bob
// 30 Alice
// 40 Bob
// 50 Alice
// 60 Bob
// 70 Alice
// 80 Bob
// 90 Alice
// 100 Bob