int** levelOrderBottom(struct TreeNode* root, int* returnSize, int** returnColumnSize)
{
    if (!root)
    {
        *returnSize = 0;
        *returnColumnSize = NULL;
        return NULL;
    }

    struct TreeNode* nodeStore[2][1000];
    int** preAns = (int **)malloc(sizeof(int *) * 1000);
    int* preColumnSize = (int *)malloc(sizeof(int) * 1000);
    int tag, nodeCount, nodeStoreCount[2];

    tag = 0;
    *returnSize = 0;
    nodeStore[tag][0] = root;
    nodeStoreCount[tag] = 1;

    for (;0 != nodeStoreCount[tag]; tag ^= 1)
    {
        int* array = (int *)malloc(sizeof(int) * nodeStoreCount[tag]);
        for (int i = 0; i < nodeStoreCount[tag]; i++) 
        {
            array[i] = nodeStore[tag][i]->val;
        }
        preColumnSize[*returnSize] = nodeStoreCount[tag];
        preAns[(*returnSize)++] = array;

        nodeCount = 0;
        for (int i = 0 ; i < nodeStoreCount[tag]; ++i)
        {
            if (nodeStore[tag][i]->left)
                nodeStore[tag^1][nodeCount++] = nodeStore[tag][i]->left;
            if (nodeStore[tag][i]->right)
                nodeStore[tag^1][nodeCount++] = nodeStore[tag][i]->right;
        }
        nodeStoreCount[tag^1] = nodeCount;
    }

    int** ans = (int**)malloc(sizeof(int*) * (*returnSize));
    (*returnColumnSize) = (int*)malloc(sizeof(int) * (*returnSize));
    for (int i = 0 , j = (*returnSize) -1; i < (*returnSize); i++, j--)
    {
        ans[i] = preAns[j];
        (*returnColumnSize)[i] = preColumnSize[j];
    }

    return ans;
}