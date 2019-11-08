#include <iostream>
#include <set>

using namespace std;

int main() {
    int total;
    while (cin >> total) {
        if (!total)
            break;
        multiset<int> s;
        long acc = 0;
        for (int i = 0; i < total; i++) {
            int size;
            cin >> size;
            for (int j = 0; j < size; j++) {
                int tmp;
                cin >> tmp;
                s.insert(tmp);
            }
            auto end = s.end();
            end--;
            acc += *end - *s.begin();
            s.erase(s.begin());
            s.erase(end);
        }
        cout << acc << endl;
    }
    return 0;
}