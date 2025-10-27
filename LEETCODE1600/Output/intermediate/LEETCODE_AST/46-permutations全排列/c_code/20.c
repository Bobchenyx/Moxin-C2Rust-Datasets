int Getnum(int num) {
    if (num == 0) {
        return 0;
    }
    int temp = 1;
    for (int i = 1; i <= num; i++) {
        temp = temp*i;
    }
    return temp;
}
void Dfs(int **ret, int* nums, int numsSize, int* returnSize, int** returnColumnSizes, int index, int book[], int temp[])
{
    if (index == numsSize) {
        ret[*returnSize] = (int *)malloc(sizeof(int) * numsSize);
        for (int i = 0; i < numsSize; i++) {
            ret[*returnSize][i] = temp[i];
        }
        (*returnColumnSizes)[*returnSize] = numsSize;
        (*returnSize)++;
        return;        
    }
    for (int i = 0; i < numsSize; i++) {
        if (book[i] == 0) {
            temp[index] = nums[i];           
            book[i] = 1;
            Dfs(ret, nums, numsSize, returnSize, returnColumnSizes, index + 1, book, temp);
            book[i] = 0;
        }

    }
    return;
}
int** permute(int* nums, int numsSize, int* returnSize, int** returnColumnSizes){
    *returnSize = 0;
    int len = Getnum(numsSize);
    int **ret = (int **)malloc(sizeof(int *) * len);
    int *book = (int *)malloc(sizeof(int) * (numsSize));
    int *temp = (int *)malloc(sizeof(int) * (numsSize));
    memset(book, 0, sizeof(int) * (numsSize));
    memset(temp, 0, sizeof(int) * (numsSize));
    *returnColumnSizes = (int *)malloc(sizeof(int) * len);
    if (nums == NULL || numsSize == 0) {
        returnColumnSizes[0][0] = 0;
        return ret;
    }
    
    Dfs(ret, nums, numsSize, returnSize, returnColumnSizes, 0, book, temp);
    free(book);
    free(temp);
    return ret;
}