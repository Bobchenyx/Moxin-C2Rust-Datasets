/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

int minDepth(struct TreeNode* root) {
	if(root == NULL)
		return 0;
	int left = minDepth(root->left);
	int right = minDepth(root->right);
	if (left == 0 && right != 0) //该节点只有右孩子，深度加上其右子树的高度
		return 1 + right;
	if (left != 0 && right == 0) //只有左孩子
		return 1 + left;
	else	//左右孩子都有的话，深度增值为左右子树中较小的哪一个
			//都没有的话，加0
		return 1 + (left > right ? right : left);
}