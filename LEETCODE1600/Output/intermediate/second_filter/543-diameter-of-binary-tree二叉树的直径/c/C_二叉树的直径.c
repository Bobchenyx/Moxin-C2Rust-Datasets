/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

int deep(struct TreeNode* root,int* Max)
{
    if(root==0)return 0;
    int left=deep(root->left,Max);
    int right=deep(root->right,Max);
    *Max=*Max>(left+right)?*Max:(left+right);
    return left>right?left+1:right+1;
}

int diameterOfBinaryTree(struct TreeNode* root){
    if(root==0)return 0;
    int max=-1;
    deep(root,&max);
    return max;
}

/*不可以这样记录最大直径

int MAX=0;

int deep(struct TreeNode* root)
{
    if(root==0)return 0;
    int left=deep(root->left);
    int right=deep(root->right);
    MAX=MAX>(left+right)?MAX:(left+right);
    return left>right?left+1:right+1;
}

int diameterOfBinaryTree(struct TreeNode* root){
    if(root==0)return 0;
    deep(root);
    return MAX;
}*/