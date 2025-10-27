struct TreeNode* buildBinaryTree(int* preorderStart, int* preorderEnd, int* inorderStart, int* inorderEnd);

struct TreeNode* buildTree(int* preorder, int preorderSize, int* inorder, int inorderSize){
    if (preorder == NULL || inorder == NULL || preorderSize == 0 || inorderSize != preorderSize) {
        return NULL;
    }
    
    return buildBinaryTree(preorder, preorder + preorderSize - 1, inorder, inorder + inorderSize - 1);
}

struct TreeNode* buildBinaryTree(int* preorderStart, int* preorderEnd, int* inorderStart, int* inorderEnd)
{
    int rootValue = preorderStart[0];
    struct TreeNode* root = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    root->val = rootValue;
    root->left = NULL;
    root->right = NULL;
    
    if (preorderStart == preorderEnd) {
        if (inorderStart == inorderEnd && *preorderStart == *inorderStart) {
            return root;
        } else {
            free(root);
            return NULL;
        }
    }
    
    //构建左子树
    int* rootInorder = inorderStart;
    int inorderLen = inorderEnd - inorderStart;
    while (rootInorder <= inorderEnd && *rootInorder != rootValue) rootInorder++;
    
    if (rootInorder == inorderEnd && *rootInorder != rootValue) {
        free(root);
        return NULL;
    }
    
    int leftInoderLen = rootInorder - inorderStart;
    int* leftPreorder = preorderStart + leftInoderLen;
    
    if (leftInoderLen > 0) {
        root->left = buildBinaryTree(preorderStart + 1, leftPreorder, inorderStart, rootInorder - 1);
    }
    
//构建右子树
    if (leftInoderLen < inorderLen) {
        root->right = buildBinaryTree(leftPreorder + 1, preorderEnd, rootInorder + 1, inorderEnd);
    }
    
    return root;
}