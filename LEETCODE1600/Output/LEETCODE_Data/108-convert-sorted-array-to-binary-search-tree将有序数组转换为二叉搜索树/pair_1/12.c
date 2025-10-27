struct TreeNode* sortedArrayToBST(int* nums, int numsSize){
  if (numsSize <= 0) return NULL;
  struct TreeNode* p = (struct TreeNode*)calloc(1, sizeof(struct TreeNode));
  p->val = nums[numsSize / 2];
  p->left = sortedArrayToBST(nums, numsSize / 2);
  p->right = sortedArrayToBST(nums + numsSize / 2 + 1, (numsSize - 1)/ 2);
  return p;
}