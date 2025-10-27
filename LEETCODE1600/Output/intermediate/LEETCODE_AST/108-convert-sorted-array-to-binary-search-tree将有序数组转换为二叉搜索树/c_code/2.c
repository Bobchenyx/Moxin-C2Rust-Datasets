/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


struct TreeNode* sortedArrayToBST(int* nums, int numsSize){
    int inx;
    struct TreeNode *n = NULL;
    if (numsSize <= 0) {
        return NULL;
    }
    n = (struct TreeNode*)calloc(1, sizeof(struct TreeNode));
    if (n == NULL) {
        return NULL;
    }
    inx = numsSize / 2;
    n->val = nums[inx];
    n->left = sortedArrayToBST(nums, inx);
    n->right = sortedArrayToBST(nums + inx + 1, numsSize - inx - 1);
    return n;
}