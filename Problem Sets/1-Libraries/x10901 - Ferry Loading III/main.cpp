#include <iostream>
#include <queue>
#include <stack>
#include <set>

using namespace std;

int main() {
    int total;
    while (cin >> total) {
        int op, n;
        queue<int> q;
        priority_queue<int> pq;
        stack<int> st;
        bool is_q = true;
        bool is_pq = true;
        bool is_st = true;
        int available = 3;
        for (int i = 0; i < total; i++) {
            cin >> op >> n;
            if (op == 1) {
                if (is_q)
                    q.push(n);
                if (is_pq)
                    pq.push(n);
                if (is_st)
                    st.push(n);
            } else {
                if (is_q) {
                    if (q.empty() || q.front()!=n) {
                        is_q = false;
                        available--;
                    } else
                        q.pop();
                }
                if (is_pq) {
                    if (pq.empty() || pq.top()!=n) {
                        is_pq = false;
                        available--;
                    } else
                        pq.pop();
                }
                if (is_st) {
                    if (st.empty() || st.top()!=n) {
                        is_st = false;
                        available--;
                    } else
                        st.pop();
                }
            }
        }
        if (available > 1)
            cout << "not sure" << endl;
        else if (!available)
            cout << "impossible" << endl;
        else {
            if (is_q)
                cout << "queue" << endl;
            else if (is_pq)
                cout << "priority queue" << endl;
            else if (is_st)
                cout << "stack" << endl;
        }
    }
    return 0;
}