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
    long long  ans=0;
    void dfs(TreeNode *root,int L,int R){
        if(root==nullptr){
            return ;
        }
        dfs(root->left,L,R);
        if(root->val<=R&&root->val>=L){
            ans+=root->val;
        }
        dfs(root->right,L,R);
    }
    int rangeSumBST(TreeNode* root, int L, int R) {
        dfs(root,L,R);
        return ans;
    }
};