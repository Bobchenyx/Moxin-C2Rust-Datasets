class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        helper(root,res);
        return res;
    }

    void helper(TreeNode* root,vector<int>& res){
        if(root==NULL)
            return;
        helper(root->left,res);
        res.emplace_back(root->val);
        helper(root->right,res);
    }
};