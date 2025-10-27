/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

int rangeSumBST(struct TreeNode* root, int L, int R){
    return (root) ? ( (root->val < L || root->val > R) ? (rangeSumBST(root->left,L,R) + rangeSumBST(root->right,L,R)) : (root->val + rangeSumBST(root->left,L,R) + rangeSumBST(root->right,L,R)) ) : 0;
}