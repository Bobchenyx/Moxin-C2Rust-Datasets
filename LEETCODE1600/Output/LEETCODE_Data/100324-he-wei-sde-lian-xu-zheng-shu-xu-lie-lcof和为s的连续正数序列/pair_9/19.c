/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** findContinuousSequence(int target, int* returnSize, int** returnColumnSizes){
    if (!returnSize || !returnColumnSizes)
        return NULL;
    int start, end, start_max, end_min, end_max, sum;

    start = 1;
    end = 2;
    sum = 3;
    *returnSize = 0;
    start_max = (target - 1)/2;
    end_min = (int)sqrt(2 * target) - 1;
    end_max = (target + 1)/2;
    //printf("end_max - end_min:%d\n", end_max - end_min);
    int **resArr = (int **)malloc((end_max - end_min) * sizeof(int *));
    int *columnSizes = (int *)malloc((end_max - end_min) * sizeof(int));
    while (start <= start_max) {
        //printf("start:%d end:%d sum:%d\n", start, end, sum);
        if (sum < target) {
            end++;
            sum += end;
        }
        else if (sum > target) {
            sum -= start;
            start++;
        }
        else {
            resArr[*returnSize] = (int *)malloc((end - start + 1) * sizeof(int));
            for (int i = 0; i <= end - start; i++) {
                resArr[*returnSize][i] = i + start;
            }
            columnSizes[*returnSize] = end - start + 1;
            //printf("returnSize:%d, columeSize:%d\n", *returnSize, columnSizes[*returnSize]);
            ++*returnSize;
            sum -= start * 2 + 1;
            sum += end + 1;
            start += 2;
            end++;
        }
    }
    *returnColumnSizes = columnSizes;

    /*printf("Print result: fin returnSize:%d\n", *returnSize);
    for (int i = 0; i < *returnSize; i++) {
        printf("row [%d] size:%d, content:", i, (*returnColumnSizes)[i]);
        for (int j = 0; j < (*returnColumnSizes)[i]; j++)
            printf("%d", resArr[i][j]);
        printf("\n");
    }*/

    return resArr;
}