bool isBalanced(struct TreeNode* root){
    if(root == NULL)
    {
        return true;
    }
    if(isBalanced( root->right)==true && isBalanced( root->left)==true) 
    {
        int r = root->right?root->right->val:0;
        int l = root->left?root->left->val:0;
        root->val = (r > l? r : l)+1;
        if(r-l>1 || r-l<-1)
            return false;
        return true; 
    }   
    else
        return false;
}