#include <iostream>
#include <map>
#include <unordered_map>
#include <set>

using namespace std;

int main() {
    string command;
    unordered_map<int, int> m;
    map<int, set<int>> time;
    int Q_num, Period;
    while (cin >> command) {
        if (command == "#")
            break;
        cin >> Q_num >> Period;
        m[Q_num] = Period;
        time[Period].insert(Q_num);
    }
    int query;
    cin >> query;
    while (query--) {
        int first = time.begin()->first;
        int cur = *time[first].begin();
        cout << cur << endl;
        time[first].erase(time[first].begin());
        time[first+m[cur]].insert(cur);
        if (time[first].empty())
            time.erase(first);
    }
    return 0;
}