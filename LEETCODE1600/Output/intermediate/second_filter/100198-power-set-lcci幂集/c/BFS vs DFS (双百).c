/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** subsets(int* nums, int numsSize, int* returnSize, int** returnColumnSizes){
    int **ans,top=-1,*p,x;
    *returnSize = 1<<numsSize;
    ans = (int**)malloc(sizeof(int*)*(1<<numsSize));
    p = (int*)malloc(sizeof(int)*(1<<numsSize));
    p[++top] = 0;
    for (int i=0;i<numsSize;i++){
        x = top;
        for (int j=0;j<=x;j++){
            ans[++top] = (int*)malloc(sizeof(int)*(p[j]+1));
            p[top] = p[j] + 1;
            for (int k=0;k<p[j];k++)
                ans[top][k] = ans[j][k];
            ans[top][p[j]] = nums[i];
        }
    }
    *returnColumnSizes = p;
    return ans;
}