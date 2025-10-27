/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

void trans(struct TreeNode* root, int cur, int *sum)
{
	if (root == NULL) {
		return;
	}
	cur = cur * 2 + root->val;
	if (root->left == NULL && root->right == NULL) {
		*sum = (*sum + cur) % ((int)pow(10,9) + 7);
		return;
	}
	trans(root->left, cur, sum);
	trans(root->right, cur, sum);
	return;
}
int sumRootToLeaf(struct TreeNode* root){
	int sum = 0;
	trans(root, 0, &sum);
	return sum;
}