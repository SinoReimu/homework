#include "includes/tree.h"
#include <iostream>

using namespace std;

void Tree::addLeft (TreeNode* a, string b) {
	TreeNode  *af = new TreeNode;
	a->left = af;
}

void Tree::addRight (TreeNode* a, string b) {
	TreeNode  *af = new TreeNode;
	a->right = af;
}

void Tree::showTree (TreeNode* rt) {
	TreeNode* cur = rt;
	cout << rt->content;
	if (rt->left!=NULL) {
		cout << "(left:";
		showTree(rt->left);
	}
	if (rt->right!=NULL) {
		cout << ",right:";
		showTree(rt->right);
		cout << ")";
	}
}
