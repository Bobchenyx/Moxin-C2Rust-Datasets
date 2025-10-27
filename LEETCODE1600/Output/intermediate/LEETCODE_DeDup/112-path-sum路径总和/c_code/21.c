/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


bool hasPathSum(struct TreeNode* root, int sum){
     //怎么个计算法,注意是看根节点到叶节点的和
    if(!root){
        return false;
    }
    else if(root->val == sum && !root->left && !root->right){
        return true;
    }
    else
        return hasPathSum(root->left,sum - root->val) || hasPathSum(root->right,sum - root->val);
}