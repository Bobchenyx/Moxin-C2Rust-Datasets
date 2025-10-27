struct TreeNode *creatnewnode(int num){
      struct TreeNode* temp = malloc(sizeof(struct TreeNode));
        temp->right = NULL;
        temp->left = NULL;
        temp->val = num;
        return temp;
}
struct TreeNode* recursionsortedarray(int* nums, int lo, int hi)
{
	if (lo >= hi) return NULL;

	int mid = (hi + lo) / 2;
    struct TreeNode* root =  creatnewnode(nums[mid]);
    root->left = recursionsortedarray(nums, lo, mid);
    root->right = recursionsortedarray(nums, mid + 1, hi);
	
    return root;

}

struct TreeNode* sortedArrayToBST(int* nums, int numsSize){
    return recursionsortedarray(nums, 0, numsSize);
}