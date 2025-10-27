/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int sum;
void  dfs(struct TreeNode* root){
    if(root == NULL)
        return 0;

    dfs(root->right);
    sum += root->val;
    root->val = sum;
    dfs(root->left);
}

struct TreeNode* convertBST(struct TreeNode* root){
    sum = 0;
    dfs(root);
    return root;
}