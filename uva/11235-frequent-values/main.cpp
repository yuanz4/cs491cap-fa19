#include <cstdio>

using namespace std;

struct TreeNode {
	int lv, mv, rv;
	int lc = 1, mc = 1, rc = 1;
	TreeNode* left = NULL;
	TreeNode* right = NULL;
	TreeNode() {}
	TreeNode(int x) : lv(x), mv(x), rv(x) {}
};

TreeNode* merge(TreeNode* l, TreeNode* r) {
	int new_lv = l->lv, new_lc = l->lc;
	int new_rv = r->rv, new_rc = r->rc;
	int new_mv = l->mv, new_mc = l->mc;
	if (r->mc > new_mc) {
		new_mv = r->mv;
		new_mc = r->mc;
	}
	if (l->rv == r->lv) {
		int combine = l->rc + r->lc;
		if (combine > new_mc) {
			new_mv = l->rv;
			new_mc = combine;
		}
	}
	if (new_lv == new_mv)
		new_lc = new_mc;
	if (new_rv == new_mv)
		new_rc = new_mc;
	TreeNode* cur = new TreeNode();
	cur->lv = new_lv;
	cur->lc = new_lc;
	cur->mv = new_mv;
	cur->mc = new_mc;
	cur->rv = new_rv;
	cur->rc = new_rc;
	cur->left = l;
	cur->right = r;
	return cur;
}

TreeNode* build(int* num, int left, int right) {
	TreeNode* cur;
	if (left == right) {
		cur = new TreeNode(num[left]);
	} else {
		TreeNode* l = build(num, left, (left+right)/2);
		TreeNode* r = build(num, (left+right)/2+1, right);
		cur = merge(l, r);
	}
	return cur;
}

TreeNode* query(TreeNode* node, int L, int R, int i, int j) {
	if (i > R || j < L)
		return NULL;
	if (L >= i && R <= j)
		return node;
	TreeNode* l = query(node->left, L, (L+R)/2, i, j);
	TreeNode* r = query(node->right, (L+R)/2+1, R, i, j);
	if (!l)
		return r;
	if (!r)
		return l;
	return merge(l, r);
}

int main() {
	int n, q;
	int num[100005] = {0};
	while (scanf("%d", &n) && n) {
		scanf("%d", &q);
		for (int k = 0; k < n; k++)
			scanf("%d", &num[k]);
		TreeNode* root = build(num, 0, n-1);
		int i, j;
		for (int k = 0; k < q; k++) {
			scanf("%d %d", &i, &j);
			TreeNode* result = query(root, 0, n-1, i-1, j-1);
			printf("%d\n", result->mc);
		}
	}
	return 0;
}