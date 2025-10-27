/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
 int max = 0;
int depth(struct TreeNode* root){
    int l = 0, r = 0;

    if (root == NULL)
        return 0;
    l = depth(root->left);
    r = depth(root->right);

    max = max > (l + r) ? max : (l + r);
    return 1 + (l > r ? l : r);
}

int diameterOfBinaryTree(struct TreeNode* root){
    max = 0;

    depth(root);
    return max; 
}