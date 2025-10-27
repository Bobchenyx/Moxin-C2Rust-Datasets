//  获取数中节点的个数，以便于来创建数组
int getSize(struct TreeNode* node)
{
    if(node == NULL)
    {
        return 0 ;
    }
    else
    {
        return (getSize(node->left)+getSize(node->right)+1);
    }
}

void traversal(struct TreeNode* node ,int* returnSize ,int* arr)
{
    if(node == NULL)
    {
        return;
    }
    else
    {
        traversal(node->left,returnSize,arr);
        arr[*returnSize] = node->val ; (*returnSize)++ ; 
        traversal(node->right,returnSize,arr); 
    }
}

int* inorderTraversal(struct TreeNode* root, int* returnSize){
    int size = getSize(root);

    int* arr = malloc(sizeof(int)*size);

    *returnSize = 0;//先把返回的数组大小设置为0，以便在遍历的时候确定要填写的位置

    traversal(root,returnSize,arr);

    return arr;
}