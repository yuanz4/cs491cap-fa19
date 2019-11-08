#include <bits/stdc++.h>

using namespace std;

bool v[26];
int e[26];

int find(int i) {
    if (i != e[i])
        return e[i] = find(e[i]);
    return i;
}

void update(int i, int j) {
    int a = find(i);
    int b = find(j);
    if (a == b)
        return;
    else
        e[a] = b;
}

int main() {
    int test;
    scanf("%d ", &test);
    char str[60];
    while (test--) {
        for (int i = 0; i < 26; i++) {
            e[i] = i;
            v[i] = false;
        }
        int a, b;
        while (fgets(str, 60, stdin)) {
            if (str[0] == '*')
                break;
            a = str[1]-'A';
            b = str[3]-'A';
            update(a, b);
            v[a] = v[b] = true;
        }
        int tree, acorn = 0;
        fgets(str, 60, stdin);
        unordered_set<int> root;
        for (int i = 0; i < strlen(str)-1; i+=2) {
            int cur = str[i]-'A';
            if (!v[cur])
                acorn++;
            else
                root.insert(find(cur));
        }
        tree = root.size();
        printf("There are %d tree(s) and %d acorn(s).\n", tree, acorn);
    }
    return 0;
}