/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int max;
int counthigh(struct TreeNode* root);
int countdis(struct TreeNode* root);
void preordertree(struct TreeNode* root);

int diameterOfBinaryTree(struct TreeNode* root){
    max=0;
    if(!root||(!root->left&&!root->right))
        return 0;
    preordertree(root);


    return max;
}

void preordertree(struct TreeNode* root)
{
    if(root)
    {
        int count=countdis(root);
        if(max<count)
            max=count;
    }
    else
        return;
    preordertree(root->left);
    preordertree(root->right);
    return;
}

//统计以每个结点为转折得最大路径长度
int countdis(struct TreeNode* root)
{
    if(!root)
        return 0;
    int res=0;
    int left=counthigh(root->left);
    int right=counthigh(root->right);

    res=left+right;

    return res;
}
int counthigh(struct TreeNode* root)
{
    if(!root)
        return 0;
    int left=0;
    if(root->left!=NULL)
        left=counthigh(root->left);
    int right=0;
    if(root->right!=NULL)
        right=counthigh(root->right);
    int height=(left>right?left:right)+1;
    return height;
}