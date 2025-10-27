在左右子树中查找大于根节点值的最小节点
int findMin(struct TreeNode *root,int data)
{
	if(!root) return -1;
	if(root->val > data) return root->val;
	
	int left = findMin(root->left,data);
	int right = findMin(root->right,data);
	
	if(left==-1) return right;
	if(right==-1) return left;
	
	return left > right ? right : left;
	
}

int findSecondMinimumValue(struct TreeNode* root){
	return findMin(root,root->val);
}