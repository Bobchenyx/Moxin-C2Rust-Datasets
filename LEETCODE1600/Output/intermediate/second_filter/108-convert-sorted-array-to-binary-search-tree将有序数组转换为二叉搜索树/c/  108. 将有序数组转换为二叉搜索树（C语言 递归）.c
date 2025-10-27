void InitNode(struct TreeNode *nowNode){
	nowNode->left  = NULL;
	nowNode->right = NULL;
}

struct TreeNode * CreateBST( int* nums , int left , int right ){
	if(left > right){
		return NULL;
	}
	
	struct TreeNode *NowNode = (struct TreeNode *)malloc(sizeof(struct TreeNode));
	InitNode (NowNode);
	
	if( right == left){
		NowNode->val = nums[left];
	}else{
		int nownums = (right + left )/2;
		NowNode->val = nums[nownums];
		
		NowNode->left = CreateBST(nums,left,nownums-1);
		NowNode->right = CreateBST(nums,nownums+1,right);
	}
	return NowNode;
}

struct TreeNode* sortedArrayToBST(int* nums, int numsSize){
	return CreateBST(nums,0,numsSize - 1);
}