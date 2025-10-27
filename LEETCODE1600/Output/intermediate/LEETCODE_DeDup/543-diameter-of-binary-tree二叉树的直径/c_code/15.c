/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int maxLenthOfTreeNode(struct TreeNode* tNode,int *maxr)
{
    if(tNode->left==NULL && tNode->right==NULL)
    {    
        return 0;
    }
    else if(tNode->left==NULL)
    {
        int ml=maxLenthOfTreeNode(tNode->right,maxr)+1;
        if(ml>*maxr)
        {
            *maxr=ml;
        }        
        return ml;
    }
    else if(tNode->right==NULL)
    {
        int ml=maxLenthOfTreeNode(tNode->left,maxr)+1;
        if(ml>*maxr)
        {
            *maxr=ml;
        }        
        return ml;
    }
    else
    {
        int l=maxLenthOfTreeNode(tNode->left,maxr)+1;
        int r=maxLenthOfTreeNode(tNode->right,maxr)+1;
        if(l+r>*maxr)
        {
            *maxr=l+r;
        }
        return l>r?l:r;
    }
}

int diameterOfBinaryTree(struct TreeNode* root){
    int ans=0;
    if(root!=NULL)
    {
        maxLenthOfTreeNode(root,&ans);
    }
    
    return ans;
}