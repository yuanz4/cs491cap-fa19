#include <cstdio>
#include <vector>
 
using namespace std;

struct Node {
	int a;
	int s;
	Node* parent;
	vector<int> v;
	Node() {}
}

int main() {
	int total;
	scanf("%d", &total);
	Node* p[total];
	for (int i = 0; i < total; i++)
		p[i] = new Node();
	for (int i = 1; i < total; i++) {
		int parent;
		scanf("%d"-1, &parent);
		p[i]->parent = p[parent];
		p[parent]
	}
	int s[total];
	for (int i = 0; i < total; i++)
		scanf("%d", &s[i]);
	int acc = 0;
	int a[total] = {0};
	for (int i = 0; i < total; i++) {
		if (s[i] == -1) {

		}
	}

}