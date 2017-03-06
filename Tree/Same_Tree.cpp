#include <iostream>

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	bool isSameTree(TreeNode* p, TreeNode* q) {
		if(!p && !q)
			return true;
		else if(!p && q || p && !q)
			return false;
		return p->val == q->val && isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
	}
};
int main(int argc, char *argv[]) {
	
}

/*
Given two binary trees, write a function to check if they are equal or not.
Two binary trees are considered equal if they are structurally identical and the nodes have the same value.

给定两颗二叉树,判定其是否相等,相等条件,结构相等,节点数据相等
思路:根据条件,节点不同时为空,不相等,节点同时为空,相等
			节点同时不为空,数据不一致:不等,左子树不同:不等,右子树不同:不等,全部相同:相等
	递归实现
*/