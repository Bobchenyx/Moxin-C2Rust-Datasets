/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

int length;//设置全局变量

int diameterOfBinaryTree(struct TreeNode* root)
{
    //只需要计算出深度之和的最大值
    length=0;
    deep(root);
    return length;
}

int deep (struct TreeNode* root)
{
    int max=0;     //当前树的深度
    int leftmax=0; //左子树的深度
    int rightmax=0;//
    if(root==NULL)
    {
        return 0;
    }
    else
    {
        leftmax=deep(root->left);
        rightmax=deep(root->right);
        length=(length>=(leftmax+rightmax)?length:(leftmax+rightmax));
        return (leftmax>=rightmax?leftmax:rightmax)+1;//每次递归算深度
    }
}