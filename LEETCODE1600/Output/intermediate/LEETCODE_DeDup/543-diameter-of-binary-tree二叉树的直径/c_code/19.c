/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int rootDepth(struct TreeNode *root)
{
    int left, right;

    if (root == NULL) {
        return 0;
    }
    left = rootDepth(root->left) + 1;
    right = rootDepth(root->right) + 1;

    return left > right ? left : right;
}

int myDiameterOfBinaryTree(struct TreeNode* root){
    int left, right;
    if (root == NULL) {
        return 0;
    }

    left = rootDepth(root->left);
    right = rootDepth(root->right);

    return left + right;
}

int diameterOfBinaryTree(struct TreeNode* root)
{
    int left, right, mid;
    if (root == NULL) {
        return 0;
    }

    left = diameterOfBinaryTree(root->left);
    right = diameterOfBinaryTree(root->right);
    mid = myDiameterOfBinaryTree(root);

    return mid > (left > right ? left : right) ? mid : (left > right ? left : right);
}