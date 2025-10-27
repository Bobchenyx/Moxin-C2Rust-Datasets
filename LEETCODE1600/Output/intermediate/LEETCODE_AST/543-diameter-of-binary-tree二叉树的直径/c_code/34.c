/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

int gMaxTreeLen = 0;
#define MAX(a, b) ((a) > (b) ? (a):(b))
int GetTreeLen(struct TreeNode* root){
    if (root == NULL) {
        return -1;
    }
    int left = GetTreeLen(root->left) + 1;
    int right = GetTreeLen(root->right) + 1;
    //printf("root[%d], left:%d --- right:%d\n", root->val, left, right);
    gMaxTreeLen = MAX(gMaxTreeLen, left + right);
    return MAX(left, right);
}

int diameterOfBinaryTree(struct TreeNode* root){
    gMaxTreeLen = 0;
    GetTreeLen(root);
    return gMaxTreeLen;
}