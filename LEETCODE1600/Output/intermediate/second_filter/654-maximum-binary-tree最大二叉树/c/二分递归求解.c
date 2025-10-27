/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
struct TreeNode* createTree(int* nums, int begin, int end) {

    if(begin>end){
        return NULL;
    }
    int max = begin;
    for(int i=begin+1; i<=end; i++){
        if(nums[i] > nums[max]){
            max = i;
        }
    }
    struct TreeNode *root = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    root->val = nums[max];
    root->left = createTree(nums, begin, max-1);
    root->right = createTree(nums, max+1, end);
    return root;
}

struct TreeNode* constructMaximumBinaryTree(int* nums, int numsSize){

    return createTree(nums, 0, numsSize-1);
};