/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


//上面描述的有点不恰当，不仅仅使用了两个变量，但是整体思路依然正确，不妨碍大家阅读
int longest(struct TreeNode *root, int val, int *max)
{
    if (root == NULL)
        return 0;
    int num = 0, mark = 0, num1, num2;
    num1 = longest(root->left, root->val, max);
    if (root->val == val) //val是上一层传过来的，root->val是该节点的值
        mark = 1;//mark是用来判断返回值
    num2 = longest(root->right, root->val, max);
    if (num1 + num2 > *max)//这里的max实现了累加两边
        *max = num1 + num2;
    num = (num1 > num2) ? num1 : num2;//num只取了两边之一的最大值
    if (mark == 1)
    {
        return num + 1;
    }
    else
    {
       return 0;
    }
}
int longestUnivaluePath(struct TreeNode *root)
{
    if (root == NULL)
        return 0;
    int *max = (int *)malloc(sizeof(int));
    *max = 0;
    longest(root, root->val, max);
    return *max;
}