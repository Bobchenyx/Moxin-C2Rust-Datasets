/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

//将一个节点的子树左右互换
void swapChildTreeNode(struct TreeNode* root) {
    struct TreeNode* temp;
    temp = root -> left;
    root -> left = root -> right;
    root -> right = temp;
}

//递归进行后序遍历并完成左右互换
struct TreeNode* mirrorTree(struct TreeNode* root){
    if(root == NULL) {
        return root;
    }
    if(root -> left != NULL) {
        mirrorTree(root -> left);
    }
    if(root -> right != NULL) {
        mirrorTree(root -> right);
    }
    swapChildTreeNode(root);
    return root;
}