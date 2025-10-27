int depth(struct TreeNode *root)
{
    int ld=0,rd=0;
    if(root)
	{
        ld=depth(root->left)+1;
        rd=depth(root->right)+1;  
    }
    return ld>=rd?ld:rd;
}

void level_order_recursion(struct TreeNode *root,int **array,int * ColumnSizes,int level)
{
    if(root == NULL)
        return;

    if(array[level] == NULL)
    {
       //array[level] = (int*)malloc(sizeof(int) * pow(2,level));不为何在最后一个调用时没有通过
        array[level] = (int*)malloc(sizeof(int) * 200);
    }
    array[level][ColumnSizes[level]++] = root->val;

    if(root->left)
    {
        level_order_recursion(root->left,array,ColumnSizes,level+1);
    }
    if(root->right)
    {
        level_order_recursion(root->right,array,ColumnSizes,level+1);
    }
}

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** levelOrderRecursion(struct TreeNode* root, int* returnSize, int** returnColumnSizes)
{
    int **array = NULL;

    if(root == NULL)
    {
        *returnSize = 0;
        return NULL;
    }

    *returnSize = depth(root);
    array = (int**)malloc(sizeof(int*) * (*returnSize));
    if(array == NULL)
    {
        printf("failed malloc for array!\n");
        return NULL;
    }
        

    memset((void*)array,0,sizeof(int*) * (*returnSize));

    *returnColumnSizes = (int*)malloc(sizeof(int) * (*returnSize));
    if(*returnColumnSizes == NULL)
    {
        printf("failed malloc csize\n");
        return NULL;
    }

    memset((void*)*returnColumnSizes,0,sizeof(int) * (*returnSize));
    
    level_order_recursion(root,array,*returnColumnSizes,0);
    return array;
}