/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
struct MySectInfo {
	int max;
	int *left;
	int leftSize;
	int *right;
	int rightSize;
};

void findSect(int* nums, int numsSize, struct MySectInfo *info)
{
	int i;
	int maxInx = -1;
	int max = INT_MIN;
	for (i = 0; i < numsSize; i++) {
		if (nums[i] < max) {
			continue;
		}
		max = nums[i];
		maxInx = i;
	}
	info->max = max;
	info->left = &nums[0];
	info->leftSize = maxInx;
	info->right = &nums[maxInx + 1];
	info->rightSize = numsSize - (maxInx + 1);
	//printf("max = %d, leftSize = %d, rightSize = %d\n", info->max, info->leftSize, info->rightSize);
	return;
}

struct TreeNode* constructMaximumBinaryTree(int* nums, int numsSize){
	struct MySectInfo sectInfo = { 0 };
	struct TreeNode* node = (struct TreeNode*)calloc(1, sizeof(struct TreeNode));
	if (numsSize <= 0) {
		return NULL;
	}
	if (numsSize == 1) {
		node->val = nums[0];
		return node;
	}
	findSect(nums, numsSize, &sectInfo);
	node->val = sectInfo.max;
	node->left = sectInfo.leftSize == 0 ? NULL : constructMaximumBinaryTree(sectInfo.left, sectInfo.leftSize);
	node->right = sectInfo.rightSize == 0 ? NULL : constructMaximumBinaryTree(sectInfo.right, sectInfo.rightSize);
	return node;
}