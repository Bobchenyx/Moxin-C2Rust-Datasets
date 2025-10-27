c++
class Solution {
public:
    bool hasPathSum(TreeNode* root, int sum) {
        if (nullptr == root) return 0 == sum;
        return hasPathSum(root->left, sum - root->val) || hasPathSum(root->right, sum - root->val)
    }
};