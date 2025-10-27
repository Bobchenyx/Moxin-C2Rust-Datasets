/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** findContinuousSequence(int target, int* returnSize, int** returnColumnSizes){
    int l,r,i,j,k;
    int sum = 0;
    int ls[400] = {0};
    int lens[400] = {0};
    for(l = 1, r = 1, i = 0; r <= target/2+2 && l <= r;)//此处+2是因为下面是先sum+r再r++,也就是r指向的是窗口的右边界的下一个数
    {
        if(sum < target)
        {
            sum += r;
            r++;
        }
        else if(sum > target)
        {
            sum -= l;
            l++;
        }
        else
        {
            ls[i] = l;
            i++;
            sum += r;
            r++;
        }
    }
    *returnColumnSizes = (int *)malloc(sizeof(int)*i);
    int **a = (int **)malloc(i*sizeof(int *));
    for(j = 0; j < i; j++)
    {
        a[j] = (int *)malloc(lens[j]*sizeof(int));
        a[j][0] = ls[j];
        for(k = 1; k < lens[j]; k++)
        {
            a[j][k] = ++(ls[j]);
        }
        (*returnColumnSizes)[j] = k;
    }
    *returnSize = i;
    return a;
}