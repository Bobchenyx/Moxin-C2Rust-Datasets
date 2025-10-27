/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

struct TreeNode *dfs(int *nums, int l, int r) {
    if (l > r) return NULL;
    int mid = ((r - l) >> 1) + l ;
    struct TreeNode *root = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    root->val = nums[mid];
    root->left = dfs(nums, l, mid - 1);
    root->right = dfs(nums, mid + 1, r);
    return root;
}

struct TreeNode* sortedArrayToBST(int* nums, int numsSize){
    return dfs(nums, 0, numsSize - 1);
}