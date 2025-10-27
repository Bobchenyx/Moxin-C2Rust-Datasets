/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


bool isSameTree(struct TreeNode* p, struct TreeNode* q){
    if (p == NULL && q == NULL) {
        return true;
    } else if (p== NULL || q== NULL) {
        return false;
    }
    if (p != NULL && q != NULL) {
        if (p->val != q->val) {
            return false;
        }
    }
    if (((p->left == NULL)&&(q->left != NULL))||
        ((p->left != NULL)&&(q->left == NULL))||
        ((p->right == NULL)&&(q->right != NULL))||
        ((p->right != NULL)&&(q->right == NULL))) {
        return false;
    }
    if ((p->left == NULL)&&(q->left == NULL) ||
        (isSameTree(p->left, q->left) == true)) {
        if (((p->right == NULL)&&(q->right == NULL)) ||
            (isSameTree(p->right, q->right) == true)) {
            return true;
        } else {
            return false;
        }
    } else {
        return false;
    }
}