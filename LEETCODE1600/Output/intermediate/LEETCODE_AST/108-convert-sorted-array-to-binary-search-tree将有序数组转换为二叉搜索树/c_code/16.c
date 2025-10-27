/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


struct TreeNode* sortedArrayToBST(int* nums, int numsSize){
    
    if(numsSize==0)return NULL;
    
    struct TreeNode *cur;
    cur=(struct TreeNode*)malloc(sizeof(struct TreeNode));
    int rootNUm=numsSize/2;
    cur->val=nums[rootNUm];
    if(numsSize==1){
        cur->left=NULL;
        cur->right=NULL;
        return cur;
    }
    numsSize--;
    int leftNUm=numsSize-numsSize/2;
    cur->left=sortedArrayToBST(nums,leftNUm);
    nums+=(leftNUm+1);
    cur->right=sortedArrayToBST(nums,numsSize/2);

    return cur;
}