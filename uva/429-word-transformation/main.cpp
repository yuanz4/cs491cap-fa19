#include <bits/stdc++.h>
using namespace std;

const int MX = 1000;

int main() {
	int test;
	scanf("%d", &test);
	string tmp;
	while (test--) {
		vector<string> wordList;
		while (cin >> tmp, tmp[0] != '*') {
			wordList.push_back(tmp);
		}
		vector<vector<string>> query;
		char cur[MX], a[MX], b[MX];
		fgets(cur, MX, stdin);
		while (fgets(cur, MX, stdin)) {
			if (strlen(cur) < 3)
				break;
			sscanf(cur, "%s %s ", a, b);
			query.push_back({string(a), string(b)});
		}

		unordered_map<string, vector<string>> m;
		for (string w: wordList) {
            for (int i = 0; i < w.size(); i++) {
                string tmp = w.substr(0,i)+"*"+w.substr(i+1,w.size()-1-i);
                m[tmp].push_back(w);
            }
        }

		for (auto p: query) {
			string beginWord = p[0];
			string endWord = p[1];
	        int l = beginWord.size();
			unordered_map<string, int> level;
	        for (string w: wordList)
	            level[w] = -1;

	        queue<string> q;
	        q.push(beginWord);
	        level[beginWord] = 0;
	        int ret = 0;
	        while (!q.empty()) {
	            string w = q.front();
	            q.pop();
	            if (w == endWord) {
	                ret = level[w];
	                break;
	            }
	            int step;
	            if (w == beginWord)
	                step = 0;
	            else
	                step = level[w];
	            for (int i = 0; i < l; i++) {
	                string tmp = w.substr(0,i)+"*"+w.substr(i+1,l-1-i);
	                if (m.count(tmp)) {
	                    for (string s: m[tmp]) {
	                        if (level[s] == -1) {
	                            q.push(s);
	                            level[s] = step+1;
	                        }
	                    }
	                }
	            }
	        }
	        cout << beginWord << " " << endWord << " " << ret << endl;
		}
		if (test)
			printf("\n");
	}
	return 0;
}