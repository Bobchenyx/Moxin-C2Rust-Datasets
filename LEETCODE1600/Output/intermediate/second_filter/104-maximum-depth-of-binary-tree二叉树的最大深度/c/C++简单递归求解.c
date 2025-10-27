class Solution {
public:
    int maxDepth(TreeNode* root) {
        int L=0,R=0;
        if(root == NULL)
            return 0;
        else
        {    
            L = maxDepth(root->left);
            R = maxDepth(root->right);
            return (L>R?L:R)+1;
        }
    }
};