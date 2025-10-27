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
//法一：递归
 void PostOrder(struct TreeNode*root,int *returnSize,int *res)//递归遍历，不多赘述
 {
     if(!root) return ;
     PostOrder(root->left,returnSize,res);
     PostOrder(root->right,returnSize,res);
     res[(*returnSize)++]=root->val;
 }
int TreeSize(struct TreeNode* root)//求得动态树的size
{
    if(!root) return 0;
    return TreeSize(root->left)+TreeSize(root->right)+1;
}


int* postorderTraversal(struct TreeNode* root, int* returnSize){

int size=TreeSize(root);
int *res=malloc(sizeof(int)*size);
*returnSize=0;
PostOrder(root,returnSize,res);

return res;
}