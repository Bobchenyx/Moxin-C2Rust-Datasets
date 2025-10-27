int longestUnivaluePath(struct TreeNode* root){
    
    int seekPath( struct TreeNode *root, int *pAns );

    int ans = 0;
    seekPath( root, &ans );

    return ans;
}

int seekPath( struct TreeNode *root, int *pAns )
{
    if( !root || !root->left && !root->right )
        return 0;
    
    int leftTree, rightTree, leftPath, rightPath;
    leftTree = seekPath( root->left, pAns );
    rightTree = seekPath( root->right, pAns );

    leftPath = ( root->left && root->val == root->left->val ) ? ( 1 + leftTree ) : 0;
    rightPath = ( root->right && root->val == root->right->val ) ? ( 1 + rightTree ): 0;

    if( leftPath + rightPath > *pAns )
        *pAns = leftPath + rightPath;

    return ( leftPath > rightPath ) ? leftPath : rightPath;
}