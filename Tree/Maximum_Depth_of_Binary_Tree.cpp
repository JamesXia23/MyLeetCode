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
	int maxDepth(TreeNode* root) {
		if(!root)
			return 0;
		return max(maxDepth(root->left), maxDepth(root->right)) + 1;
	}
};
int main(int argc, char *argv[]) {
	
}
/*
Given a binary tree, find its maximum depth.

The maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.

给出一颗二叉树,求树高
思路: 二叉树的树高由其最高的子树的树高加1可得,而且空节点树高为0,可以递归实现
*/