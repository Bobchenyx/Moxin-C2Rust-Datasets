/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
bool myHasPathSum(struct TreeNode* root, int sum){
    bool left = false, right = false;

    if (root->left == NULL && root->right == NULL) {
        if (sum - root->val == 0) {
            return true;
        } else {
            return false;
        }
    }
    
    if (root->left) {
        left = myHasPathSum(root->left, sum - root->val);
    }
    if (root->right) {
        right = myHasPathSum(root->right, sum - root->val);
    }

    return left || right;
}

bool hasPathSum(struct TreeNode* root, int sum){
    if (root == NULL) {
        return false;
    }

    return myHasPathSum(root, sum);
}