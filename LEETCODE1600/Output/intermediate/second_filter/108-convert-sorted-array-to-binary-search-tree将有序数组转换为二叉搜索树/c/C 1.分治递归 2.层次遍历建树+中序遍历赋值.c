#include <stdio.h>
#include <stdlib.h>
// /**
//   Definition for a binary tree node.
// struct TreeNode {
//     int val;
//     struct TreeNode* left;
//     struct TreeNode* right;
// };
struct TreeNode* helper(int* nums, int left, int right) {
    if (left > right)
        return NULL;
    struct TreeNode* t;
    t = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    int mid = (left + right) / 2;
    t->val = nums[mid];
    t->left = helper(nums, left, mid - 1);
    t->right = helper(nums, mid + 1, right);
    return t;
}
struct TreeNode* sortedArrayToBST(int* nums, int numsSize) {
    return helper(nums, 0, numsSize - 1);
}