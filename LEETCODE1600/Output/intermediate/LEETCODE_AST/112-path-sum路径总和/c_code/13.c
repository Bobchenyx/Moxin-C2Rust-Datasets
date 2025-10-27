/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


bool hasPathSum(struct TreeNode* root, int sum){
   if (!root) return false; //如果只有根节点为空的话返回false
   if ((sum==root->val)&&!root->left&&!root->right) //叶子节点等于sum
   {
       return true;
   }
   int diff = sum - root->val;
   return (hasPathSum(root->left,diff) || hasPathSum(root->right,diff));
    
}