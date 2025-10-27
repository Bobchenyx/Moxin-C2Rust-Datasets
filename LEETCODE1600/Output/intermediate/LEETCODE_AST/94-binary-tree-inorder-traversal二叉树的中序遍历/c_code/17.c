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
void inorder(struct TreeNode *root, int *returnSize, int *res)
{
    if(!root)
    {
        return;
    }
    inorder(root->left,returnSize,res);
    res[(*returnSize)++] = root->val;
    inorder(root->right, returnSize,res);
}

int nodeNum(struct TreeNode *root)
{
    if(!root)
    {
        return 0;
    }
    return nodeNum(root->left)+nodeNum(root->right)+1;
}

int* inorderTraversal(struct TreeNode* root, int* returnSize)
{
    //入参检查
    if(!root)
    {
        *returnSize = 0;
        return NULL;
    }
    //递归
    int len = nodeNum(root);
    int *result = (int*)malloc(sizeof(int)*len);
    memset(result,0,sizeof(int)*len);
    *returnSize = 0;
    inorder(root, returnSize, result);
    return result;
}