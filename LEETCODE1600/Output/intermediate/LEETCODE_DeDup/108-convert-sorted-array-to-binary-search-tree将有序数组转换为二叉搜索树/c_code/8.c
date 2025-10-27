/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

void dfs(struct TreeNode** root, int *nums, int l, int r){
    if (l > r)
        return;

    int mid = (l + r)/2;
    //printf("mid=%d l=%d r=%d\n",mid, l, r);
    *root = malloc(sizeof(struct TreeNode));
    
    (*root)->val = nums[mid];
    (*root)->left = NULL;
    (*root)->right = NULL;
    dfs(&(*root)->left, nums, l, mid - 1);    
    dfs(&(*root)->right, nums, mid + 1, r);
}


struct TreeNode* sortedArrayToBST(int* nums, int numsSize){

    if (numsSize == 0)
        return NULL;

    struct TreeNode *root; 

    dfs(&root, nums, 0, numsSize -1);
    return root;
}