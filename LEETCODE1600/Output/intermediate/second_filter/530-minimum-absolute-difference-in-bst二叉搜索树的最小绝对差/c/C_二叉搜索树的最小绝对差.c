/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
void minTree(struct TreeNode* Root,int* lastVal, int* Min)
{
    if(Root==0) return;

    minTree(Root->left,lastVal,Min);

    int i= *lastVal>Root->val? *lastVal-Root->val: Root->val-*lastVal;
    *Min=*Min<i?*Min:i;
    *lastVal=Root->val;

    minTree(Root->right,lastVal,Min);
}

int getMinimumDifference(struct TreeNode* root){
    int result=(~((unsigned)0))>>1,lastVal=(~((unsigned)0))>>1;
    minTree(root,&lastVal,&result);
    return result;
}