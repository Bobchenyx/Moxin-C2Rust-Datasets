/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


void calcDepth(struct TreeNode* root, int *leftHeight, int *rightHeight, int *max) {
    if (root->left == NULL && root->right == NULL) {
        *leftHeight = *rightHeight = *max = 0;
        return;
    }

    int tmpL;
    int tmpR;
    int maxL = 0;
    int maxR = 0;

    if (root->left) {
        tmpL = tmpR = 0;
        calcDepth(root->left, &tmpL, &tmpR, &maxL);
        *leftHeight = fmax(tmpL, tmpR) + 1;
    }
    if (root->right) {
        tmpL = tmpR = 0;
        calcDepth(root->right, &tmpL, &tmpR, &maxR);
        *rightHeight = fmax(tmpL, tmpR) + 1;
    }

    *max = fmax(maxL, maxR);
    *max = fmax(*max, *leftHeight+*rightHeight);
    return;
}


int diameterOfBinaryTree(struct TreeNode* root){
    if (!root) return 0;
    int l=0,r=0,m=0;
    calcDepth(root, &l, &r, &m);
    return m;
}