int count(struct TreeNode *pNode, int Count)
{
    int val = 0;
    int sum = 0;
    val = (Count * 10 + pNode->val);
    if (pNode->left == NULL && pNode->right == NULL) {
        return val;
    }

    if (pNode->left) {
       sum +=  count(pNode->left, val);
    }

    if (pNode->right) {
        sum += count(pNode->right, val);
    }

    return  sum;
}

int sumNumbers(struct TreeNode* root){
    if (root == NULL) {
        return 0;
    }
    return count(root, 0);
}