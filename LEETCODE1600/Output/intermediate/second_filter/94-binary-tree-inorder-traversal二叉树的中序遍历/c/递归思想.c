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

 int treeSize(struct TreeNode* root)
 {
     if (root == NULL)
     {
         return 0;
     } 
     return treeSize(root->left) + treeSize(root->right) +1;
 }

void zhongxu(struct TreeNode* root,int * p,int * index)
{
    if(root == NULL)
        return;
    zhongxu(root->left,p,index);
    p[(*index)++] = root->val;
    zhongxu(root->right,p,index);
    
}

int* inorderTraversal(struct TreeNode* root, int* returnSize){
    int treesize = treeSize(root);
    * returnSize = 0;
    if (treesize == 0)
    {
        return NULL;
    }
    int * pArray = (int *)malloc(sizeof(int) * treesize);
    zhongxu(root,pArray,returnSize);
    return pArray;



}