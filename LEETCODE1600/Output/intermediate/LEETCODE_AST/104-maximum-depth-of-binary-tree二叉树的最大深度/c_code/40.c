/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


int maxDepth(struct TreeNode* root){
	if(root == NULL){
		return 0;
	}

	int left_length = maxDepth(root->left) + 1;
	int right_length = maxDepth(root->right) + 1;
	
	if( left_length >= right_length){
		return left_length;
	}else{
		return right_length;
	}
}