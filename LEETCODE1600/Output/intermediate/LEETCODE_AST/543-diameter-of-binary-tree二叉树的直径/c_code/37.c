/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

int g_Max;
int NodePath(struct TreeNode *root) {
    if (root == NULL) {
        return 0;
    }
    int leftMax, rightMax;
    leftMax = rightMax = 0;
    leftMax += NodePath(root->left);
    rightMax += NodePath(root->right);
    if (leftMax + rightMax >= g_Max) {
        g_Max = leftMax + rightMax;
    }
    return leftMax >= rightMax ? (leftMax + 1) : (rightMax + 1);
}

int diameterOfBinaryTree(struct TreeNode* root){
    g_Max = 0;
    int ret = NodePath(root);
    return g_Max;
}