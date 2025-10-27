/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


bool isSameTree(struct TreeNode* p, struct TreeNode* q)
{
    if(p == NULL && q == NULL)
        return true;//都为空，相等。
    if(!p||!q)    //由于上面的判断不成立，则T1，T2至少有一个不为空
        return false;//一个空，一个不空，不相等
    if(p->val == q->val) //如果根节点相等
        return isSameTree(p->left,q->left) && isSameTree(p->right,q->right);//判断左右子树是否都相等
    else 
        return false;
}