/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
               

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */



int TreeSize(struct TreeNode* root)
{
    if(!root)
        return 0;
    return TreeSize(root->left)+TreeSize(root->right)+1;
}


void inorder(struct TreeNode* root,int* returnSize,int* a)
{
    if(!root)
        return;
    inorder(root->left,returnSize,a);
    a[(*returnSize)++]=root->val;
    inorder(root->right,returnSize,a);
}

int* inorderTraversal(struct TreeNode* root, int* returnSize)
{
    int size=TreeSize(root);
    int* res=(int*)malloc(size*sizeof(int));
    memset(res,0,size);
    *returnSize=0;
    inorder(root,returnSize,res);
    return res;   


}