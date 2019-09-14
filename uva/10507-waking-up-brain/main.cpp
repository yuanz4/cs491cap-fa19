#include <cstdio>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

int main() {
	int area, link;
	while (scanf("%d %d", &area, &link) != EOF) {
		char wake[4];
		int total[26] = {0};
		scanf("%s", wake);
		for (int i = 0; i < 3; i++)
			total[wake[i]-'A'] = 1;
		int waked = 3;
		char connect[3];
		unordered_map<int, vector<int>> m;
		unordered_set<int> unwaked;
		for (int i = 0; i < link; i++) {
			scanf("%s", connect);
			int first = connect[0]-'A';
			int second = connect[1]-'A';
			m[first].push_back(second);
			m[second].push_back(first);
			if (!total[first])
				unwaked.insert(first);
			if (!total[second])
				unwaked.insert(second);
		}
		int year = 0;
		while (!unwaked.empty()) {
			vector<int> v;
			int size = unwaked.size();
			for (auto it = unwaked.begin(); it != unwaked.end(); it++) {
				int neigh = 0;
				for (int nei: m[*it]) {
					if (total[nei])
						neigh++;
				}
				if (neigh >= 3)
					v.push_back(*it);
			}
			for (int i: v) {
				total[i] = 1;
				unwaked.erase(i);
				waked++;
			}
			year++;
			if (unwaked.size() == size) {
				printf("THIS BRAIN NEVER WAKES UP\n");
				goto next;
			}
		}
		if (waked == area)
			printf("WAKE UP IN, %d, YEARS\n", year);
		else
			printf("THIS BRAIN NEVER WAKES UP\n");
		next:;
	}
	
	return 0;
}