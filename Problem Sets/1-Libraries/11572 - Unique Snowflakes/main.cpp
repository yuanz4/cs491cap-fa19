#include <iostream>
#include <unordered_set>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int total;
    cin >> total;
    while (total--) {
        int size;
        cin >> size;
        vector<int> v(size, 0);
        unordered_set<int> s;
        for (int i = 0; i < size; i++)
            cin >> v[i];
        int i = 0, j = 0;
        int ret = 0;
        while (i < size) {
            if (j!=size && !s.count(v[j])) {
                s.insert(v[j]);
                j++;
                ret = max(ret, j-i);
            } else {
                s.erase(v[i]);
                i++;
            }
        }
        cout << ret << endl;
    }
    return 0;
}