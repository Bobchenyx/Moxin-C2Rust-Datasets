/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
bool helper(struct TreeNode* leftTree, struct TreeNode* rightTree){
    if(leftTree && rightTree){
        if(leftTree->val == rightTree->val){
            return helper(leftTree->left, rightTree->right)  && helper(leftTree->right, rightTree->left);//2.那么怎么知道左子树与右子树对不对称呢？在这我直接叫为左树和右树 答案：如果左树的左孩子与右树的右孩子对称，左树的右孩子与右树的左孩子对称，那么这个左树和右树就对称。
        }
        else{
            return false;
        }
    }
    else if(!leftTree && !rightTree){
        return true;
    }
    else{
        return false;
    }
}
bool isSymmetric(struct TreeNode* root){
    if(!root) return true;
    return helper(root->left, root->right);//递归的入口是判断一个节点的左右子树是否对称，即输入应该是该节点的左右子树节点left&right、1.怎么判断一棵树是不是对称二叉树？ 答案：如果所给根节点，为空，那么是对称。如果不为空的话，当他的左子树与右子树对称时，他对称
}