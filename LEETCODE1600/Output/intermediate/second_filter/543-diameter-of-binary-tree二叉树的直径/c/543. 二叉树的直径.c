/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int max = 0;
    int diameterOfBinaryTree(TreeNode* root) {
        if(root == NULL)
            return 0;
            
        int left = dfs(root->left);
        int right = dfs(root->right);
        int value =  left + right;
        max = max > value ? max : value;
        return max;
    }

    int dfs(TreeNode* root)
    {
        if(root == NULL)
            return 0;

        int left = dfs(root->left);
        int right = dfs(root->right);
        int value =  left + right;
        max = max > value ? max : value;
        return (left > right ? left : right) + 1;
    }
};