/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

bool find_left_right( struct TreeNode* left , struct TreeNode* right ){
	if( left == NULL && right == NULL ){
		return true;
	}else if( (left != NULL && right == NULL) || (left == NULL && right != NULL ) ){
		return false;
	}
	
	bool find_outside  = find_left_right(left->left,right->right);
	bool find_inside = find_left_right(left->right,right->left);
	
	if( find_outside && find_inside && (left->val == right->val) ){
		return true;
	}else{
		return false;
	}
}
bool isSymmetric(struct TreeNode* root){
	if( root == NULL ){
		return true;
	}
	return find_left_right(root->left,root->right);
}