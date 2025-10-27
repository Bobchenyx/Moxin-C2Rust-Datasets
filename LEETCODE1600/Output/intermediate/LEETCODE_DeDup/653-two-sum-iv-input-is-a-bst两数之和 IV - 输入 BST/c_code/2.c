/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
void find(struct TreeNode* root, int val, bool *rlt)
{
	if (root == NULL || *rlt == true) {
		return;
	}
	if (root->val == val) {
		*rlt = true;
	}
	if (val > root->val) {
		find(root->right, val, rlt);
	} else {
		find(root->left, val, rlt);
	}
	return;
}
void trans(struct TreeNode* root, int k, struct TreeNode* curnode, bool *rlt)
{
	int needVal;
	if (curnode == NULL) {
		return;
	}
	needVal = k - curnode->val;
	if (needVal != curnode->val) {
		find(root, needVal, rlt);
	}
	if (*rlt != true) {
		trans(root, k, curnode->left, rlt);
	}
	if (*rlt != true) {
		trans(root, k, curnode->right, rlt);
	}
	return;
}
bool findTarget(struct TreeNode* root, int k){
	bool rlt = false;
	trans(root, k, root, &rlt);
	return rlt;
}