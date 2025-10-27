/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

void search(struct TreeNode* p, struct TreeNode* q,int *m)
{
    if(p->val==q->val)
    {
        if(p->left!=NULL && q->left!=NULL)
          search(p->left,q->left,m);//在根节点相等的情况下，先对左子树进行递归遍历
        if(p->right!=NULL && q->right!=NULL)
          search(p->right,q->right,m);//右子树的递归遍历
        if(p->left==NULL &&q->left!=NULL)
          *m=0;
        if(p->left!=NULL &&q->left==NULL)
          *m=0;  
        if(p->right!=NULL &&q->right==NULL)
          *m=0;
        if(p->right==NULL &&q->right!=NULL)
          *m=0;
    }
    else 
      *m=0;
}

bool isSameTree(struct TreeNode* p, struct TreeNode* q)
{
    if(p==NULL &&q==NULL)
      return true;
    if(p==NULL &&q!=NULL)
      return false;
    if(p!=NULL &&q==NULL)
      return false;
    int a=1;
    int *m=&a;
    search(p,q,m);
    if(*m==1)
      return true;
    else 
      return false;
}