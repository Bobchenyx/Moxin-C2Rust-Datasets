/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
#define max(a,b) ( ((a)>(b)) ? (a):(b) )

int res = 0;
int maxDepth(struct TreeNode* root);
int diameterOfBinaryTree(struct TreeNode* root){
    //注意：最大路径长度不一定全都穿过根节点
    //C语言中不能传引用
    if(root == NULL || (root -> left == NULL && root -> right == NULL)) return 0;
    else{
        res = 0;
        maxDepth(root);
        return res;
    }
}

int maxDepth(struct TreeNode* root){
    if(root == NULL) return 0;
    else if(root -> left == NULL && root -> right == NULL) return 1;
    else {
        int lheight = maxDepth(root -> left);
        int rheight = maxDepth(root -> right);
        //res = res > (lheight + rheight) ? res : (lheight + rheight);
        res = max(res,(lheight + rheight));
        return max(lheight, rheight) + 1;
    }
}