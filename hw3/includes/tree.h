#include <iostream>
#include <cstring>

using namespace std;

#ifndef TREE_H
#define TREE_H

struct TreeNode {
	string content;
	TreeNode* left;
	TreeNode* right;
};

class Tree {
	public :
		Tree () {
			TreeNode *tn = new TreeNode;
			tn->left = NULL;
			tn->right = NULL;
			tn->content = "ROOT";
			root = tn;
		}
		void addLeft (TreeNode*, string);
		void addRight (TreeNode*, string);
		void showTree (TreeNode*);
		TreeNode* root;
};

#endif
