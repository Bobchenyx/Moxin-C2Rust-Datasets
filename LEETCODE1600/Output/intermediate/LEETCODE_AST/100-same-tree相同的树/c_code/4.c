/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


bool isSameTree(struct TreeNode* p, struct TreeNode* q){

    // One tree is NULL, the other is not NULL
    if ((p != q) && ((p == NULL) || (q == NULL))) {
        return false;
    }

    // All are NULL
    if (p == NULL) {
        return true;
    }

    // All trees are not null
    // compare their val
    if (p->val != q->val) {
        return false;
    }

    // compare their children    
    if (isSameTree(p->left, q->left) && isSameTree(p->right, q->right)) {
        return true;
    }

    return false;
}