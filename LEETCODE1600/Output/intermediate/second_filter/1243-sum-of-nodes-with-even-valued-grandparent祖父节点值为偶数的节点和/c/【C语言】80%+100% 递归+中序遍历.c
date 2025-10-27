/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


int sumEvenGrandparent(struct TreeNode* root){
    int ret = 0;
    if(root == NULL) {
        return ret;
    }

    if(root->val % 2 == 0) {
        if(root->left != NULL) {
            if(root->left->left != NULL) {
                ret = ret + root->left->left->val;
            }
            if(root->left->right != NULL) {
                ret = ret + root->left->right->val;
            }
        }

        if(root->right != NULL) {
            if(root->right->left != NULL) {
                ret = ret + root->right->left->val;
            }
            if(root->right->right != NULL) {
                ret = ret + root->right->right->val;
            }
        }        
    }
    ret = ret + sumEvenGrandparent(root->left);
    ret = ret + sumEvenGrandparent(root->right);    

    return ret;

}