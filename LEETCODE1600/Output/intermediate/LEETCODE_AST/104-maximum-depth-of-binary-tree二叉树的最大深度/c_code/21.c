/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


int maxDepth(struct TreeNode* root){
    if(!root) return 0;
    //if(!root->left && !root->right) return 1; // 注意是 && ,这句可省略
    int lt = maxDepth(root->left), rt = maxDepth(root->right);
    lt = lt > rt ? lt : rt;
    return 1+ lt; 
}