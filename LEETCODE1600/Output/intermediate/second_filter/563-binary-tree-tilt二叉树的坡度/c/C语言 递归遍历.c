/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

int trans(struct TreeNode* root, int *tilt)
{
	int lSum, rSum;
	if (root == NULL) {
		return 0;
	}
	lSum = trans(root->left, tilt);
	rSum = trans(root->right, tilt);
	*tilt += abs(lSum - rSum);
	return lSum + rSum + root->val;
}
int findTilt(struct TreeNode* root){
	int tilt = 0;
	trans(root, &tilt);
	return tilt;
}