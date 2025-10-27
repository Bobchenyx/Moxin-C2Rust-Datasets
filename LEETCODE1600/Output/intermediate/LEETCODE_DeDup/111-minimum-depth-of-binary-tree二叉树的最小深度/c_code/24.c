class Solution {
public:
    int minDepth(TreeNode* root) {
        int L=0,R=0;
        if(root == NULL)
            return 0;
        else
        {    
            L = minDepth(root->left);
            R = minDepth(root->right);
            return (L<R?L:R)+1;
        }
    }
};