#include <cstdio>
#include <vector>
#include <string>
#include <iostream>
using namespace std;

int main() {
	string s;
	while (cin >> s, s != ".") {
		int n = s.size();
		int table[n] = {0};
	    for (int i = 0, j = 1; j < n;) {
	        if (s[i] != s[j]) {
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
    	int last = table[n-1];
    	if (!last) {
    		printf("1\n");
    	} else {
    		int rest = n - last;
    		if (n % rest)
    			printf("1\n");
    		else
    			printf("%d\n", n / rest);
    	}
	}
	return 0;
}