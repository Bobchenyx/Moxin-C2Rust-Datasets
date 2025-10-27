/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

void merge(struct TreeNode** t1, struct TreeNode** t2){
    if (*t1 == NULL){
        *t1 = *t2;
        return;
    }
    if (*t2 == NULL)
        return;
    (*t1)->val += (*t2)->val;
    merge(&(*t1)->left, &(*t2)->left);
    merge(&(*t1)->right, &(*t2)->right);
}


struct TreeNode* mergeTrees(struct TreeNode* t1, struct TreeNode* t2){
    merge(&t1, &t2);
    return t1;
}