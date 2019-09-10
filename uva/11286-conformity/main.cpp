#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    int size;
    while (cin >> size) {
        if (!size)
        	break;
        unordered_map<string, int> m;
        for (int i = 0; i < size; i++) {
            string s;
            vector<int> v(5, 0);
            for (int j = 0; j < 5; j++)
                cin >> v[j];
            sort(v.begin(), v.end());
            for (int j = 0; j < 5; j++)
                s += to_string(v[j]);
        	m[s]++;
        }
        int max = 0, maxNum = 0;
        for(auto it = m.begin(); it != m.end(); it++) {
            if(it->second > max) {
                max = it->second;
                maxNum = 0;
            }
            if(it->second == max)
                maxNum += max;
        }
        cout << maxNum << endl;
    }
    return 0;
}
