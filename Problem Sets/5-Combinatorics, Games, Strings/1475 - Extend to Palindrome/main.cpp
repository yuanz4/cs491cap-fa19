#include <cstdio>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;

string shortestPalindrome(string s) {
    int n = s.size();
    string rev(s);
    reverse(rev.begin(), rev.end());
    rev = s+"#"+rev;
    cout << rev << endl;
    int table[2*n+1] = {0};
    for (int i = 0, j = 1; j < 2*n+1;) {
        if (rev[i] != rev[j]) {
            if (i > 0)
                i = table[i-1];
            else
                j++;
        } else {
            table[j] = i + 1;
            i++;
            j++;
        }
    }
    for (int i = 0; i < 2*n+1; i++)
    	printf("%d ", table[i]);
    printf("\n");
    return rev.substr(n+1,n-table[2*n])+s;
}

int main() {
	string s;
	while (cin >> s) {
		reverse(s.begin(), s.end());
		cout << shortestPalindrome(s) << endl;
	}
	return 0;
}